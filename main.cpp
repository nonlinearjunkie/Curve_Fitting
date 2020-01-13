#include <iostream>
#include <vector>
#include<bits/stdc++.h>


using namespace std;

float square(float a)
{
    return a*a;
}
float sum(vector<float>v)
{
     float sum=0;
    for (float x:v)
    {
       
        sum+=x;

    }
    return sum;
}
float determinantOfMatrix(float mat[3][3]) 
{ 
    float ans; 
    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) 
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) 
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]); 
    return ans; 
} 

void findSolution(float coeff[3][4]) 
{ 
    // Matrix d using coeff as given in cramer's rule 
    float d[3][3] = { 
        { coeff[0][0], coeff[0][1], coeff[0][2] }, 
        { coeff[1][0], coeff[1][1], coeff[1][2] }, 
        { coeff[2][0], coeff[2][1], coeff[2][2] }, 
    }; 
    // Matrix d1 using coeff as given in cramer's rule 
    float d1[3][3] = { 
        { coeff[0][3], coeff[0][1], coeff[0][2] }, 
        { coeff[1][3], coeff[1][1], coeff[1][2] }, 
        { coeff[2][3], coeff[2][1], coeff[2][2] }, 
    }; 
    // Matrix d2 using coeff as given in cramer's rule 
    float d2[3][3] = { 
        { coeff[0][0], coeff[0][3], coeff[0][2] }, 
        { coeff[1][0], coeff[1][3], coeff[1][2] }, 
        { coeff[2][0], coeff[2][3], coeff[2][2] }, 
    }; 
    // Matrix d3 using coeff as given in cramer's rule 
    float d3[3][3] = { 
        { coeff[0][0], coeff[0][1], coeff[0][3] }, 
        { coeff[1][0], coeff[1][1], coeff[1][3] }, 
        { coeff[2][0], coeff[2][1], coeff[2][3] }, 
    }; 
  
    // Calculating Determinant of Matrices d, d1, d2, d3 
    float D = determinantOfMatrix(d); 
    float D1 = determinantOfMatrix(d1); 
    float D2 = determinantOfMatrix(d2); 
    float D3 = determinantOfMatrix(d3); 
    printf("D is : %lf \n", D); 
    printf("D1 is : %lf \n", D1); 
    printf("D2 is : %lf \n", D2); 
    printf("D3 is : %lf \n", D3); 
  
    // Case 1 
    if (D != 0) { 
        // Coeff have a unique solution. Apply Cramer's Rule 
        float x = D1 / D; 
        float y = D2 / D; 
        float z = D3 / D; // calculating z using cramer's rule 
        printf("Value of x is : %lf\n", x); 
        printf("Value of y is : %lf\n", y); 
        printf("Value of z is : %lf\n", z); 
    } 
    // Case 2 
    else { 
        if (D1 == 0 && D2 == 0 && D3 == 0) 
            printf("Infinite solutions\n"); 
        else if (D1 != 0 || D2 != 0 || D3 != 0) 
            printf("No solutions\n"); 
    } 
} 
  
  

int main()
{
    int n;
    cout<<"Enter the number of data points"<<endl;
    cin>>n;
    vector<float> x(n,0),y(n,0),x1(n,0),x2(n,0),x1y(n,0),x2y(n,0),x1x2(n,0),sq_x1(n,0),sq_x2(n,0);
    
   
  
    cout<<"Enter the values of independent variable x:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]=";
        cin>>x[i];
    }
    
    cout<<"Enter the values of dependent variable y:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"y["<<i<<"]=";
        cin>>y[i];
        
    }
    transform(x.begin(),x.end(),x1.begin(),square);
    x2=x;
    
    
    
    transform(x1.begin(),x1.end(),y.begin(),x1y.begin(),multiplies<float>());
    transform(x2.begin(),x2.end(),y.begin(),x2y.begin(),multiplies<float>());
    transform(x1.begin(),x1.end(),x2.begin(),x1x2.begin(),multiplies<float>());
    transform(x1.begin(),x1.end(),sq_x1.begin(),square);
    transform(x2.begin(),x2.end(),sq_x2.begin(),square);
    
    float sum_y=sum(y);
    float sum_x1=sum(x1);
    float sum_x2=sum(x2);
    float sum_x1y=sum(x1y);
    float sum_sq_x1=sum(sq_x1);
    float sum_x1x2=sum(x1x2);
    float sum_x2y=sum(x2y);
    float sum_sq_x2=sum(sq_x2);
    
    cout<<"Augmented Matrix is:"<<endl;
    cout<<sum_x1<<"  "<<sum_x2<<" "<<n<<" "<<sum_y<<endl<<sum_sq_x1<<" "<<sum_x1x2<<" "<<sum_x1<<" "<<sum_x1y<<endl<<sum_x1x2<<"  "<<sum_sq_x2<<" "<<sum_x2<<" "<<sum_x2y<<endl;
    float aug[3][4]={{sum_x1,sum_x2,n,sum_y},
                       {sum_sq_x1,sum_x1x2,sum_x1,sum_x1y},
                       {sum_x1x2,sum_sq_x2,sum_x2,sum_x2y}};
                       
   findSolution(aug); 
    
   return 0;


}