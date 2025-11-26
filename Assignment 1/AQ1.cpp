#include <iostream>
using namespace std;

int main(){
	
	int arr[100], numArray=0;
	
	while(true){
		cout<<("\nWhat do you want to perform: \n");
		cout<<("1.Create\n");
		cout<<("2.Display\n");
		cout<<("3.Insert\n");
		cout<<("4.Delete\n");
		cout<<("5.Linear Search\n");
		cout<<("6.Exit\n");
		int num;
		cin>>num;
		switch (num) {
  			case 1:{
		    	cout<<("Enter number of elements in the array: ");
		    	cin>>numArray;
		    	cout<<("Enter of elements in this array: ");
		    	for (int i=0;i<numArray;i++){
		    		cout<<(": ");
		    		cin>>arr[i];
				}
				break;
			}
			case 2:{
			    for (int i=0;i<numArray;i++){
		    		cout<<(arr[i]);
				}
				cout<<"\n";
				break;
			}
			case 3:{
			    cout<<("At which position the number will be insterted: ");
			    int pos=0,posNum=0;
			    cin>>pos;
			    cout<<("What number should be inserted: ");
			    cin>>posNum;
			    for (int i=numArray;i>=pos;--i){
		    		if(i>pos-1){
		    			arr[i]=arr[i-1];
					}
				}
				arr[pos-1]=posNum;
				numArray++;
				break;
			}
			case 4:{
			    cout<<("At which position the number will be deleted: ");
			    int pos=0,posNum=0;
			    cin>>pos;
			    for (int i=0;i<numArray-1;i++){
		    		if(i<pos-1){
		    			arr[i]=arr[i];
					}
					else if(i>=pos-1){
						arr[i]=arr[i+1];
					}
				}
				numArray=numArray-1;
				break;
			}
			case 5:{
			    cout<<("Which number to find: ");
			    int findNum=0;
			    cin>>findNum;
                bool found=false;
			    for (int i=0;i<numArray;i++){
			    	if(arr[i]==findNum){
			    		cout<<("Element found on index")<<i;
                        found=true;
					}
				}
                if(found==false){
                    cout<<"Not Found";
                }
				break;
			}
			case 6:{
			    cout << "Exiting";
			    return 0;
			}
			default:
				cout<<"Invalid code! Try again";
		}
	}
	return 0;
}
