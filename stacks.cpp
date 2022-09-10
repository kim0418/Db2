#include<iostream>
#include<stack>

using namespace std;

void menu(){

    cout << "1.PUSH" << endl;
    cout << "2.POP" << endl;
    cout << "3.QUIT" << endl;

}

int main(int argc, char*argv[]){

    int input=0;
    int num=0;
    int count=0;

    stack<int> s;

    int *arr_stk=(int*)malloc(sizeof(int)*s.size());

    do{
	menu();
	cout << "option";
	cin >> num;
	switch(num){
	    case 1:
		cout << "Input :";
		cin >> input;
		s.push(input);
		cout << input << " is push" << endl;
		arr_stk[count]=input;
		count++;
		printf("stack : ");
		for(int i=0;i<s.size();i++){
		    cout << arr_stk[i] << "-";
		}
		cout << endl;
		break;
	    case 2:
		if(!s.empty()){
		    cout << s.top() << " is pop" << endl;
		    s.pop();
		    count--;
		    printf("stack : ");
		    for(int j=0;j<s.size();j++){
			cout << arr_stk[j] << "-";
		    }
		    cout << endl;
		}
		else{
		    cout << "Stack is empty" << endl;
		}
		break;
	    case 3:
		exit(1);
	    default:
		cout << "system error" << endl;
		exit(1);
	}
	cout << endl;
    }while(1);

    return 0;
}
