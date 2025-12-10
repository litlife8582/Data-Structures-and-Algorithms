#include<iostream>

using namespace std;

int main() {
    int n,w;
    double arr[100][3];

    cin>>n;

    for (int i=0;i<n;i++) {
        cin>>arr[i][0];
    }

    for (int i=0;i<n;i++) {
        cin>>arr[i][1];
    }

    cin>>w;

    for (int i=0;i<n;i++) {
        if (arr[i][0]!=0)
        arr[i][2]=arr[i][1]*1.0/arr[i][0];
        else arr[i][2]=0.0;
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j][2]<arr[j+1][2]) {
                double temp0=arr[j][0];
                double temp1=arr[j][1];
                double temp2=arr[j][2];
                arr[j][0]=arr[j+1][0];
                arr[j][1]=arr[j+1][1];
                arr[j][2]=arr[j+1][2];
                arr[j+1][0]=temp0;
                arr[j+1][1]=temp1;
                arr[j+1][2]=temp2;
            }
        }
    }

    double tv=0.0,tw=0.0,va=0.0,we=0.0;

    for (int i=0;i<n;i++) {
        if ((tw+arr[i][0])<=w) {
            we=arr[i][0];
            va=arr[i][1];
            tv+=va;
            tw+=we;
            cout<<we<<" "<<va<<endl;
            if (tw==w) break;
        }else{
            we=w-tw;
            va=arr[i][1]*(w-tw)/arr[i][0];
            tv+=va;
            tw+=we;
            cout<<we<<" "<<va<<endl;
            break;
        }

    }

    cout<<"Total Profit:"<<tv;

    return 0;
}