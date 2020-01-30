#include<iostream>
#include<string>
using namespace std;
namespace pascal
{
class Pascal{
	int arr[10][10], size;
public:
	int getArraySize(){
		cout << "enter the pascal array size:";
		cin >> size;
		return size;
	}
	void getPascalArray(int size){
		
		for (int i = 0; i < size; i++){
			for (int j = 0; j <= i; j++){
				if (j == 0 || i == j){
					arr[i][j] = 1;
				}
				else if (i>j){
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				}
			}
		}
		displayPascalArray(size);
	}
	void displayPascalArray(int size){
		cout << "Pascal series : "<<endl;
		for (int i = 0; i < size; i++){
			for (int j = 0; j <= i; j++){
				cout << arr[i][j];
				cout << '\t';
			}
			cout << '\n';
		}
	}

};
int main1(){
	
	Pascal obj;
	
	obj.getPascalArray(obj.getArraySize());

	
	return 0;
}
}
