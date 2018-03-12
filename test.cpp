#include<bits/stdc++.h>
using namespace std;
int arr[1004];
void heapify(int x,int size)
        {
        int index;
        if(x%2!=0)
        {
           if(arr[x/2]>arr[x] || arr[x/2]>arr[x-1])
           {
             int temp;
             if(arr[x]<arr[x-1])
              { 
              
              index=x; 
              temp=arr[x/2];
              arr[x/2]=arr[x];
              arr[x]=temp;
              }
             else 
              { 
            
              index=x-1; 
              temp=arr[x/2];
              arr[x/2]=arr[x-1];
              arr[x-1]=temp;
              }
             if((2*index+1)<=size)
             {
              heapify(2*index+1,size);
             }
             heapify(x/2,size);
           }
        }
        else
        {
          if((x+1) <= size)
          {
           if(arr[x/2]>arr[x] || arr[x/2]>arr[x+1])
           {
             int temp;
             if(arr[x]<arr[x+1])
              { 
              
              index=x; 
              temp=arr[x/2];
              arr[x/2]=arr[x];
              arr[x]=temp;
              }
             else 
              { 
            
              index=x+1; 
              temp=arr[x/2];
              arr[x/2]=arr[x+1];
              arr[x+1]=temp;
              }
             if((2*index+1)<=size)
             {
              heapify(2*index+1,size);
             }
             heapify(x/2,size);
           }
          }
          else
          {
           if(arr[x/2]>arr[x])
           {
             int temp;
            
              index=x; 
              temp=arr[x/2];
              arr[x/2]=arr[x];
              arr[x]=temp;
             
             if((2*index+1)<=size)
             {
              heapify(2*index+1,size);
             }
             heapify(x/2,size);
           }
          }
        }
        
        
        
        }


int main()
       {
       int n,k;
       cin>>n>>k;
       if(k>n)
       {
       cout<<"invalid k";
       return 0;
       }
       for(int i=0;i<n;i++)
       {
        cin>>arr[i];
       }
       
       
       int size=n-1;
       
       
       for(int i=n-1;i>=0;i--)
       {
        heapify(i,size);
        /*for(int j=0;j<n;j++)
       {
        cout<<arr[j]<<" ";
       }
        cout<<endl;*/ 
       }
       
       
       for(int i=0;i<k;i++)
       {
       int min=arr[0];
       cout<<min<<" ";
       arr[0]=arr[size];
       size--;
       heapify(0,size);
       /*for(int j=0;j<size+1;j++)
       {
        cout<<arr[j]<<" ";
       }
        cout<<endl;*/ 
       }
       return 0;
       }
