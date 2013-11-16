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
#define LEG1_ID 0
#define LEG2_ID 1
#define LEG3_ID 2
#define LEG4_ID 3

#define DEFAULT_X 95
#define DEFAULT_Y 95
#define DEFAULT_Z 80
#define LEG_Z_LIFT 30

#define NBR_SAMPLES    30    // number of samples to read 
#define NBR_AA    10    
#define WALK_MAXIMUM   70    // 
#define WALK_THRESHOLD 45    // minimum distance input value to start walking
#define LEAN_THRESHOLD  2    // minimum distance input value to start leaning forward
#define GAIT_AMPLITUDE 15

/* Robot Parameters */
#define NBR_SERVOS 12
#define NBR_LEGS 4
#define NBR_JOINTS 3        // joints per leg
#define CENTER_OFFSET 33    // distance from the center of robot and the first servo axis
#define L1 45               // distance from the first servo axis and the second servo axis
#define L2 46.8             // distance from the second servo axis and the third servo axis
#define L3 103.5            // distance from the third servo axis and the tip of the leg

/* Time Parameters */
#define SPEED     15    // Movement speed
#define STEP  0.0025    // Movement fluidity(-), rigidity(+)

/* Nunchuck Parameters */
#define NUNCHUCK_X_OFFSET 0
#define NUNCHUCK_Y_OFFSET -8
