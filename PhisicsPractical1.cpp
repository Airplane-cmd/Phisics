#include<iostream>
#include<vector>
#include<math.h>
struct MedianValueAndChanges{
	MedianValueAndChanges(int h)
	{
		RightMeasure=new double[h];
	}
      	double MedianValue;
      	double *RightMeasure;
		//double DeltaXSum;
		int Number1;};
MedianValueAndChanges Measure1(){
	  int Number;
      double MedianValue1=0;
      std::cout << "Enter number of measures: "<<std::endl;
      std::cin >> Number;
      MedianValueAndChanges Measure(Number);
      for(int i=0; i<Number; i++){
      std::cout << "Enter measured value "<<i+1<<":" << std::endl;
      std::cin >> Measure.RightMeasure[i];
      MedianValue1=MedianValue1+Measure.RightMeasure[i];}
      Measure.MedianValue=MedianValue1/Number;
	  Measure.Number1=Number;
	  //std::cout<<"Test number of measures: "<< Measure.Number1<<std::endl;
	  //delete Measure.RightMeasure;
       return Measure;
	   }

    int main()
	{
		/*int str, max = 0;
	    //std::cin >> str;
	    double **matr = new double*[str];
	    for (int i = 0,num; i < str; i++)
	    {
	        std::cin >> num;
	        if (max < num)
	            max = num;
	        matr[i] = new double[num];
	        for (int j = 0; j < num; j++)
	        {
	            matr[i][j] = double(i + 23) / double(j + 3);
	            std::cout << matr[i][j] << " ";
	        }
	        std::cout << std::endl;
	    }
	
	    std::cout << std::endl << max;
	    return 0;*/
		
		
		
		 double StudentsConstant[7];
			 StudentsConstant[0]=2.0;
			 StudentsConstant[1]=2.0;
			 StudentsConstant[2]=1.3;
			 StudentsConstant[3]=1.3;
			 StudentsConstant[4]=1.2;
			 StudentsConstant[5]=1.2;
			 StudentsConstant[6]=1.1;
	        //maxNumber=0;
	   
	   
	   
	   
	   
	   
	   
	   for(int n=0, numberOfRightMeasures;n!=1;n++)
	   {
	   	 
	    int maxNumber=1;
	    //std::vector<double> DeltaXSum;  
	    
	    //std::vector<double> InstrumentError(numberOfRightMeasures);
	   	std::vector<std::vector<double> >RightMeasureDelta(numberOfRightMeasures, std::vector<double>(maxNumber));
	    double Delta;
	   	
	   	
	   	std::cout<<"Enter number of right measures in the function: ";
	    std::cin>>numberOfRightMeasures;
	   	    double *InstrumentError = new double[numberOfRightMeasures];
	   	    double *Student = new double[numberOfRightMeasures];//массив коэффициентов Стьюдента для каждой прямо измеряемой величины
	   		int *MaxNumber = new int[numberOfRightMeasures]; 	
			double *DeltaXSum = new double[numberOfRightMeasures];
	   	    double *DeltaXAcc = new double[numberOfRightMeasures];
	   		double *DeltaX = new double[numberOfRightMeasures];	 
					  	
	   for(int i=0;i<numberOfRightMeasures;i++)
       	{
	   int g=1; 
	     std::cout<<"Enter instument's error: ";
	     std::cin>>InstrumentError[i];
	   MedianValueAndChanges Function = Measure1();
	   MaxNumber[i]=Function.Number1;
	   //Student[i]=StudentsConstant[Function.Number1-1];//колличество элементов не больше колличества данных постоянных Стьюдента
	   int num=Function.Number1;
	   std::cout<<g<<" function median value: "<<Function.MedianValue<<'\n';
	   DeltaXSum[i]=0.0;
	   for(int k=0;k<num;k++)
	{
	   Delta=Function.RightMeasure[k]-Function.MedianValue;
	   std::cout<<k+1<<" measure delta: "<<Delta<<'\n';
	   
	   RightMeasureDelta[i][k]=Delta;
	   DeltaXSum[i]+=Delta*Delta;//инициализация двумерного массива значениями delta Measure
    }
	  g++;
	  
	  
	  	if(MaxNumber[i]>maxNumber)
	  	maxNumber = MaxNumber[i];
	  	//RightMeasureDelta[i][maxNumber]=0.0;//обнуление
		  
}
      
      system("cls");
      for(int z=0;z<numberOfRightMeasures;++z)
	  {
      	for(int x=0;x<maxNumber;++x)
		  {
      		 std::cout<<"Measure "<<z+1<<"."<<x+1<<": "<<RightMeasureDelta[z][x]<<std::endl;
    	  }
		     DeltaXAcc[z] = StudentsConstant[maxNumber-1]*sqrt(DeltaXSum[z]/static_cast <double>(numberOfRightMeasures*(numberOfRightMeasures-1)));
		     if(DeltaXAcc[z]>=3*InstrumentError[z])
		        DeltaX[z] = sqrt(DeltaXAcc[z]*DeltaXAcc[z]);
		     else if(3*DeltaXAcc[z]<=InstrumentError[z])
		        DeltaX[z] = sqrt((InstrumentError[z]*InstrumentError[z]));
		     else
		        DeltaX[z] = sqrt((DeltaXAcc[z]*DeltaXAcc[z])+(InstrumentError[z]*InstrumentError[z]));
		     //std::cout<<DeltaXSum[z]<<std::endl;
		     std::cout<<"Accidental measurement error: "<<DeltaXAcc[z]<<std::endl;
		     std::cout<<"Absolute measurement error: "<<DeltaX[z]<<std::endl;
	  }
	  
	        /*delete InstrumentError;// = new double[numberOfRightMeasures];
	   	    delete Student;// = new double[numberOfRightMeasures];//массив коэффициентов Стьюдента для каждой прямо измеряемой величины
	   		delete MaxNumber;// = new int[numberOfRightMeasures]; 	
			delete DeltaXSum;// = new double[numberOfRightMeasures];
	   	    delete DeltaXAcc;// = new double[numberOfRightMeasures];
	   		delete DeltaX;*/// = new double[numberOfRightMeasures];	 
	  
	  char Answer;
      std::cout<<"NEXT FUNCTION?(Y/N)";
      std::cin>>Answer;
      if(Answer=='Y')
	  {
	  	n = 0;
      	system("cls");
      	delete MaxNumber;
      } }
     return 0;
      }
      


        
        
        
        
        
        
