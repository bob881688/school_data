#include <iostream>
using namespace std;

int main(){
    int map_x, map_y;
    cin >> map_x >> map_y;

    int robot_x, robot_y, robot_face;
    char face_input;
    char face_char[4] = {'E', 'S', 'W', 'N'};

    int **lost = new int*[map_x + 1];
    for ( int i = 0; i < map_x + 1; i++ ){
        lost[i] = new int[map_y + 1];
    }

    while ( cin >> robot_x >> robot_y >> face_input ){
        string action;
        cin >> action;

        switch (face_input){
        case 'E':
            robot_face = 0;
            break;
        case 'S':
            robot_face = 1;
            break;
        case 'W':
            robot_face = 2;
            break;
        case 'N':
            robot_face = 3;
            break;
        }

        int lost_flag = 0;
        for ( int i = 0; i < action.length(); i++ ){
            if ( action[i] == 'R' ){
                robot_face += 1;

                if ( robot_face == 4 ){
                    robot_face -= 4;
                }

            }else if ( action[i] == 'L' ){
                robot_face -= 1;

                if ( robot_face == -1 ){
                    robot_face += 4;
                }

            }else if ( action[i] == 'F' ){
                int x_after = robot_x;
                int y_after = robot_y;
                if ( robot_face == 0 ){
                    x_after++;
                }else if ( robot_face == 1 ){
                    y_after--;
                }else if ( robot_face == 2 ){
                    x_after--;
                }else if ( robot_face == 3 ){
                    y_after++;
                }

                if ( ( x_after > map_x || x_after < 0 || y_after > map_y || y_after < 0 ) && lost[robot_x][robot_y] != 1 ){
                    lost_flag = 1;
                    lost[robot_x][robot_y] = 1;
                    cout << robot_x << " " << robot_y << " " << face_char[robot_face] << " LOST" << endl;
                    break;

                }else if ( x_after <= map_x && x_after >= 0 && y_after <= map_y && y_after >= 0 ){
                    robot_x = x_after;
                    robot_y = y_after;
                }
            }
        }

        if ( lost_flag == 0 ){
            cout << robot_x << " " << robot_y << " " << face_char[robot_face] << endl;
        }
    }

    for ( int i = 0; i < map_x + 1; i++ ){
        delete[] lost[i];
    }
    delete[] lost;
}