/* 
 *  Quadruped
 *  - Author: Eric Truong
 */
 
/* Global Parameters */
#define NBR_BEHAVIOUR 1

#define LEG1_ID 0
#define LEG2_ID 1
#define LEG3_ID 2
#define LEG4_ID 3

#define JOINT1_ID 0
#define JOINT2_ID 1
#define JOINT3_ID 2

/* Time Parameters */
#define SPEED      50    // Movement speed
#define FLUIDITY 0.01    // Movement fluidity(-), rigidity(+)

/* Robot Parameters */
#define JOINT1_OFFSET 90     // angle difference from math model and real servo 1
#define JOINT2_OFFSET 28      
#define JOINT3_OFFSET 180    
#define CENTER_OFFSET 33     // distance from the center of robot and the first servo axis
#define L1 45                // distance from the first servo axis and the second servo axis
#define L2 46.8              // distance from the second servo axis and the third servo axis
#define L3 103.5             // distance from the third servo axis and the tip of the leg

#define NBR_SERVOS 12
#define NBR_LEGS 4
#define NBR_JOINTS 3    // joints per leg

#define DEFAULT_X 95
#define DEFAULT_Y 95
#define DEFAULT_Z 95

/* Arduino Parameters */
#define SERVO_1_PIN   2
#define SERVO_2_PIN   3
#define SERVO_3_PIN   4
#define SERVO_4_PIN   5
#define SERVO_5_PIN   6
#define SERVO_6_PIN   7 
#define SERVO_7_PIN   8
#define SERVO_8_PIN   9
#define SERVO_9_PIN  10
#define SERVO_10_PIN 11
#define SERVO_11_PIN 12
#define SERVO_12_PIN 13


/* Structured Type */
struct positions {
    double x[NBR_LEGS];     // coordinates in the robot's coordinate system 
    double y[NBR_LEGS];
    double z[NBR_LEGS];
    double center_x;
    double center_y;
    double center_z;
};
typedef struct positions Positions;    // Type holding input positions

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
    Positions pos;  
    boolean flag;                        // inform if want control or not
    int angles[NBR_LEGS][NBR_JOINTS];    // angles sent to servos   
};
typedef struct behaviour Behaviour;      // Type holding final angles and control flag.


/* Declarations */
extern Behaviour idle;
extern Behaviour *winner_behaviour;
