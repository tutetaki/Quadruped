/* 
 *  Quadruped
 *  - Author: Eric Truong
 */

#ifndef PARAMETERS_H
#define PARAMETERS_H

/* Arduino Parameters */
#define BAUDRATE 9600

#define PIN_SERVO_1   2
#define PIN_SERVO_2   3
#define PIN_SERVO_3   4
#define PIN_SERVO_4   5
#define PIN_SERVO_5   6
#define PIN_SERVO_6   7 
#define PIN_SERVO_7   8
#define PIN_SERVO_8   9
#define PIN_SERVO_9  10
#define PIN_SERVO_10 11
#define PIN_SERVO_11 12
#define PIN_SERVO_12 13

/* Global Parameters */
#define NBR_BEHAVIOUR 1

#define LEG1_ID 0
#define LEG2_ID 1
#define LEG3_ID 2
#define LEG4_ID 3

#define DEFAULT_X 95
#define DEFAULT_Y 95
#define DEFAULT_Z 95

/* Time Parameters */
#define SPEED     15    // Movement speed
#define STEP  0.0025    // Movement fluidity(-), rigidity(+)

/* Robot Parameters */
#define ANGLE1_OFFSET 90     // angle difference from math model and real servo 1
#define ANGLE2_OFFSET 28      
#define ANGLE3_OFFSET 180    
#define CENTER_OFFSET 33     // distance from the center of robot and the first servo axis
#define L1 45                // distance from the first servo axis and the second servo axis
#define L2 46.8              // distance from the second servo axis and the third servo axis
#define L3 103.5             // distance from the third servo axis and the tip of the leg

#define NBR_SERVOS 12
#define NBR_LEGS 4
#define NBR_JOINTS 3    // joints per leg


/* Structured Type */
struct state {
    double x[NBR_LEGS];     // coordinates in the robot's coordinate system 
    double y[NBR_LEGS];
    double z[NBR_LEGS];
    double center_x;
    double center_y;
    double center_z;
};
typedef struct state State;    // Type holding input positions

struct leg {                
    int x_offset;           // offset of the leg to the center of the robot 
    int y_offset;           
    int z_offset;           
    int x;                  // coordinates in the leg's coordinate system 
    int y;                  
    int z;                  
    int u;                  
    int n;                  
    float a[NBR_JOINTS];    // intermediate angle values
};
typedef struct leg Leg;     // Type holding intermediate lengths and angles.

struct behaviour {
    State state;  
    boolean flag;                        // inform if want control or not
    int angles[NBR_SERVOS];    // angles sent to servos   
};
typedef struct behaviour Behaviour;      // Type holding final angles and control flag.


/* Declarations */
extern Behaviour idle;
extern Behaviour *winner_behaviour;

#endif
