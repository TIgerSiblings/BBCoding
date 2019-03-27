#include <kipr/botball.h>
/*This program is for our awesome Lenard. Lenard will start with activating the camera first. Using the camera, 
The robot will decide if the building on fire is to the right,or to the left. if the camera doesnt detect
an object, then the building on fire is the one al the way to the left.

Step2: the robot will move forward until black in detected by sensor
step3: the robot will grap the water, turn right, move backward until is touches the PVC to be straight
step4: mmove towards the burning building, then turn to the building on the right. if building was not 
found bby the camera, turn left to grap botguy or the mayor to place in the base, THATS IT"
*/
void armUp();// left the arm up using the the 3 motors in ports (0,1 and 3) 
void armDown();// moves the arm down gradualt using the sevo in port 0, position is 1640
void cameraRead();
void turnLeft();
void turnRight();
void forward();
void backward();
void xCode();// the function that will run if the building on fire is the one on the left
void yCode();// the function that will run if the building in the middle is on fire
void zCode();// the function that will run if the building on the right is on fire
int x, y, z;

int main()
{

  //msleep(4000);
  create_connect();
  printf("connected to create");  
  camera_open();
  printf("opened Camera");  
  cameraRead();
  printf("fishied reading from Camera");
  enable_servos();
  set_servo_position(0,1826);// arm down 
   set_servo_position(3,1858); // claw lift up
   set_servo_position(2,1846);// claw open all the way 
   msleep(5000);
    if (x >5) {
        xCode();// this means the building is on the left
    }
    
    if (y>5) {
        yCode();// this means that the building is in the middle
    }
    if (z>5) {
        zCode();// this means thaat the building is on the right
    }
    
 
   
    ao();
    msleep(1000);
   
    return 0;
}

void xCode(){
    
    
}
void yCode(){
    
}

void zCode(){
    turnLeft();
    msleep(500);
}
void armUp(){
 //int n = 1745 // intinal position for servo 0 when the arm is down 
 //while (get_servo_position(0)>513){
	//mav(0,100);
    //mav(1,100);
    //mav(3,100);
    //msleep(4000);// move the arm up for 4 seconds
   set_servo_position(0,474);// servo moves the arm up to the exact position 
   // msleep(500);
 }

void armDown(){
 while (get_servo_position (0)<1650)
      {
	 set_servo_position(0, (get_setvo_posisiton(0)+50)
	
			    }// while
 }//function
 void cameraRead(){
     camera_open();// connect the camera
     camera_update();
     printf("updated Camera");  
     msleep(5000);// while (digital(8)==0){
     camera_update();
       if (get_object_count(0)==0){
           printf("no object found.\n");
           int x =1;
           x=x+9;
           }
       else{
           if (get_object_center_x(0,0)<80)// 80
              {
               printf("object on the left\n");
              
                int y =1;
           		y=y+9;
               }
           
           else{
               printf("object on the right\n");
               int z =1;
           		z=z+9;
               }
       }// else
    }//while

 void turnLeft(){
     create_drive_direct(-100,100);
 }
 void turnRight(){
     create_drive_direct(100,-100);
 }
 void forward(){
     create_drive_direct(-100,-100);
 }
 void backward(){
     create_drive_direct(100,100);
 }
