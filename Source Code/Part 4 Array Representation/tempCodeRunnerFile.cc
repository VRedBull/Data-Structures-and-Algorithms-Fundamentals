
    int **A;
    *A = new int[3];
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];
    
    int a=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            *(*(A+i)+j)=a;
            a++;
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<A[i][j]<<" "<<flush;
        }
        cout<<endl;
    }
    way 