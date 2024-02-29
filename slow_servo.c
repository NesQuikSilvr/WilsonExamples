

const int left_motor = 3;
const int right_motor = 0;

const int button_left = 1;
const int button_right = 2;

void moveServo(int port, int target_position, int time) {
    int current_position = get_servo_position();

    //Going up
    while (current_position < target_position) {
        current_position++; //This "increments" (adds +1 to) our current_position
        set_servo_position(port, current_position);
        msleep(time);
    }

    //Going down
    while (current_position > target_position) {
        current_position--; //This "decrements" (subtracts -1 to) our current_position
        set_servo_position(port, current_position);
        msleep(time);
    }
}

void drive(int left_speed, int right_speed, int time) {

    motor(left_motor, left_speed);
    motor(right_motor, right_speed);
    msleep(time);

}

int pressed(int port) {
    return digital(port) == 1;
}

int main() {
    
    enable_servos();

    set_servo_position(0, 0);
    msleep(1000);
    
    int position = get_servo_position(0);

    if (position > 2000) {

        while(get_servo_position(0) != 2000) {

            position--;
            printf("%d\n", position);
            set_servo_position(0, position);
            msleep(5);

        }

    }
    else {

        while(get_servo_position(0) != 2000) {

            position++;
            printf("%d\n", position);
            set_servo_position(0, position);
            msleep(5);

        }

    }


    //1. What is the function's job?
        //Slowly move the servo!
        //moveServo()

    //2. What information does the function give back to us?
        //No information!
        //void

    //3. What information does the function NEED to do its job?
        //Target position
        //Starting position
        //Pause time between intermediate movements
        //Servo port

    move_servo(1000);
    move_servo(2000);
    move_servo(0);
    
    moveServo(0, 1000);

    int myInt = 5;

    int left_motor = 3;
    int right_motor = 0;

    motor(right_motor, 100);
    motor(left_motor, -100);
    msleep(2000);


    int total_cats = 10;
    int minutes = 5;
    int roughness_level = 2;

    //Not a real function, unfortunately :(
    //But now we know what the numbers mean!
    petCats(total_cats, minutes, roughness_level);


    int right_motor = 3;

    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);
    motor(right_motor, 100);



    set_servo_position(0, 1000);

    set_servo_position(arm, 1000);

    armUp();

    armDown();

    arm(2000);



    int port = 0;
    int target_position = 2000;
    int time = 10;
    int current_position = get_servo_position();

    //Going up
    while (current_position < target_position) {
        current_position++; //This "increments" (adds +1 to) our current_position
        set_servo_position(port, current_position);
        msleep(time);
    }

    //Going down
    while (current_position > target_position) {
        current_position--; //This "decrements" (subtracts -1 to) our current_position
        set_servo_position(port, current_position);
        msleep(time);
    }
    

    return 0;
}


int main() {

    int claw = 0;
    int arm = 3;

    //Move servos to default positions
    enable_servos();
    move_servo(claw, 2000, 0);
    move_servo(arm, 2000, 20);

    //Drive to object
    drive(100, 100, 2500);
    drive(-100, 100, 1500);
    ao();

    //Pick up the object
    move_servo(arm, 0, 20);
    move_servo(claw, 0, 0);
    move_servo(arm, 2000,20);

    return 0;
}