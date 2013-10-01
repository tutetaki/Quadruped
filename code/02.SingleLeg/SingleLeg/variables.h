/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#define LEG1_ID 0
#define LEG2_ID 1
#define LEG3_ID 2
#define LEG4_ID 3

/* Time Parameters */
#define PERIOD 1000

/* Robot Parameters */
#define CENTER_OFFSET 33     // distance from the center of robot and the first servo axis
#define L1 45                // distance from the first servo axis and the second servo axis
#define L2 46.8              // distance from the second servo axis and the third servo axis
#define L3 103.5             // distance from the third servo axis and the tip of the leg

#define NBR_SERVOS 3
#define NBR_JOINTS 3    // joints per leg

#define DEFAULT_X 90
#define DEFAULT_Y 90
#define DEFAULT_Z 90

/* Arduino Parameters */
#define SERVO_1_PIN   2
#define SERVO_2_PIN   3
#define SERVO_3_PIN   4


/* Structured Type */
struct positions {
    double x;
    double y;
    double z;
    double center_x;
    double center_y;
    double center_z;
};
typedef struct positions Positions;    // Type holding input positions

struct leg {    
    int x_offset;           // offset of the leg to the center of the robot 
    int y_offset;           
    int z_offset;           
    int x;                  
    int y;                  
    int z;         
    int u;                  
    int n;                  
    float a[NBR_JOINTS];    // intermediate angle values
};
typedef struct leg Leg;     // Type holding intermediate lengths and angles.
    