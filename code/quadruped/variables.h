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
#define PERIOD 1000

/* Robot Parameters */
#define CENTER_OFFSET 33     // distance from the center of robot and the first servo axis
#define L1 45                // distance from the first servo axis and the second servo axis
#define L2 46.8              // distance from the second servo axis and the third servo axis
#define L3 103.5             // distance from the third servo axis and the tip of the leg

#define NBR_SERVOS 12
#define NBR_LEGS 4
#define NBR_JOINTS 3    // joints per leg

#define DEFAULT_X 90
#define DEFAULT_Y 90
#define DEFAULT_Z 90

/* Arduino Parameters */
#define FIRST_SERVO_PIN 2


/* Structured Type */
struct positions {
    int x[NBR_LEGS];
    int y[NBR_LEGS];
    int z[NBR_LEGS];
    int center_x;
    int center_y;
    int center_z;
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

struct behaviour {
    int angles[NBR_LEGS][NBR_JOINTS];    // angle values sent to servos
    boolean flag;                        // inform if want control or not
    Positions pos;
};
typedef struct behaviour Behaviour;      // Type holding final angles and control flag.


/* Declarations */
extern Behaviour idle;
extern Behaviour *winner_behaviour;
