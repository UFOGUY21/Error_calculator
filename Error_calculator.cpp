#include<iostream>
#include<cmath>

using namespace std;

int main(){
float data[21]={-1.088,-0.940,-1.000,-0.765,-0.598,-0.510,-0.440,-
0.359,-0.141,-0.055,-
0.051,0.166,0.191,0.376,0.480,0.650,0.786,0.831,0.986,1.040,1.065};
float mean;
float sd;
float sd_error;
float err_bound;
float dy;
float omega_r;
float omega_m;
float omega_b;
float sum;
int i;

cout<<"==================================\n";
cout<<"******* PreLab Excercise 1 *******\n";
cout<<"==================================\n\n";
cout<<"Elio S Cusi\n";
cout<<"ENAE464\n\n";
cout<<"Part 1: obtain the total uncertainty of the y-data\n";

//this loop calculates the mean of the Y data points
sum=0;
for(i=0;i<21;i++){
   sum=sum+data[i];
   }
mean=sum/21;
cout<<"The mean is: "<<mean<<"\n";

 
 //this loop calculates the standard deviation of the Y data points
sum=0;
for(i=0;i<21;i++){
   sum=sum+pow((data[i]-mean),2);
   }
sd=sqrt(sum/(21-1));
cout<<"The standard deviation is: "<<sd<<"\n";

//this part calculates the stardard error
sd_error=sd/sqrt(21);
cout<<"The stardard error is: "<<sd_error<<"\n";

//this section calculates the max and the min values of the Y data 
point and the error bound
float min=data[0];
float max=data[0];
for(i=0;i<21;i++){
if(data[i]<min){
  min=data[i];
  }

if(data[i]>max){
  max=data[i];
  }
}
err_bound=abs(max-min);
cout<<"The error bound is: "<<err_bound<<"\n";

//This part calculates the uncertainty of the Y data points
dy=sqrt((pow(err_bound/2,2)+pow(sd_error,2)));
cout<<"The total uncertainty of the width is: "<<dy<<"\n";
cout<<"===============================\n";
cout<<"Part 2: Obtain the standard deviation of sigma_m and sigma_b 
of the linear regression\n";

//This part calculates the standard deviation about the error of the 
linear regression
sum=0;
float datax[21]={-10,-9,-8,-7,-6,-5,-4,-3,-2,-
1,0,1,2,3,4,5,6,7,8,9,10};
float m=0.1134;
float b=0.0296;
for(i=0;i<21;i++){
    sum=sum+(pow(data[i]-(m*datax[i]+b),2))/(21-2);
   }
omega_r=sqrt(sum);
cout<<"The standard deviation about the error of the linear 
regression is: "<<omega_r<<"\n";

//this part calcualtes the linear regresion error (standard 
deviation about the error, slope and Y-intercerp
sum=0;
float sum_2=0;
for(i=0;i<21;i++){
    sum=sum+pow(datax[i],2);
    sum_2=sum_2+datax[i];
  }
omega_m=omega_r*sqrt(21/(21*sum-pow(sum_2,2)));
cout<<"The standard deviation about the slope is : "<<omega_m<<"\n";
omega_b=omega_r*sqrt((sum)/(21*sum-pow(sum_2,2)));
cout<<"The standard deviation about the the y-intercept is: 
"<<omega_b<<"\n";
return 0;
