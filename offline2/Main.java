import java.util.Scanner;

public class Main {
    public static void PrintStack(StackADT<Integer>s, int l,int d)
    {
        if(d==1){
            if (s.length()==0)
                return;
            int x = s.pop();
            PrintStack(s,l,d);
            if (s.length()==l)
                System.out.print(x);
            else
                System.out.print(x + " ");
            s.push(x);
        }else{
            if (s.length()==0)
                return;
            int x = s.pop();
            if (s.length()==0)
                System.out.print(x);
            else
                System.out.print(x + " ");
            PrintStack(s,l,d);
            s.push(x);
        }
    }
    public static void print(StackADT<Integer>s, int d){
        System.out.print("<");
        PrintStack(s,s.length()-1,d);
        System.out.println(">");
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int K,d=1;
        K = sc.nextInt();

        ///have to change this line if the list is not an integer list
        Integer[] a = new Integer[K];
        for(int i=0; i<K; i++){
            a[i] = sc.nextInt();
        }
        ///have to change this line if the list is not an integer list
        ///this line differ depending on array based list or linked list
        StackADT<Integer> myStack  = new Arr<>(a,K);
        print(myStack,d);
        while (true){
            int Q;
            ///have to change this line if the list is not an integer list
            Integer P;
            Q = sc.nextInt();
            P = sc.nextInt();
            if(Q==6)
                d = P;
            if(Q==0)
                break;
            else if(Q==1) {
                myStack.clear();
                print(myStack,d);
                System.out.println(-1);
            }
            else if(Q==2){
                myStack.push(P);
                print(myStack,d);
                System.out.println(-1);
            }
            else if(Q==3){
                ///have to change this line if the list is not an integer list
                Integer t = myStack.pop();
                print(myStack,d);
                System.out.println(t);
            }
            else if(Q==4){
                int s = myStack.length();
                print(myStack,d);
                System.out.println(s);
            }
            else if(Q==5){
                ///have to change this line if the list is not an integer list
                Integer v = myStack.topValue();
                print(myStack,d);
                System.out.println(v);
            }
            else if(Q==6){
                myStack.setDirection(P);
                print(myStack,d);
                System.out.println(-1);
            }
        }
    }
}
