#include<iostream>
#include<stack>


using namespace std;

void stand(){
      
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.QUIT\n");
}

void protocal

int main(int argc, char* argv[]){

    stack<int> s;
    
    int input=0;
    int menu=0;
    do{
    stand();
    scanf("%d",&menu);
    switch(menu){
	case 1:
	    printf("INPUT: ");
	    scanf("%d",&input);
	    s.push(input);
	    printf("%d input\n",input);
	    break;
	case 2:
	    if(!s.empty()){
		cout << s.top() << "is POP!\n";
		s.pop();
	    }
	    else{
		printf("STACK is empty!\n");
	    }
	    break;
	case 3:
	    exit(1);
	default:
	    printf("system error\n");
	    exit(1);
    }

    }while(1);
}
