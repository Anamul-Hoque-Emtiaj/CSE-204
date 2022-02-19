import java.util.Scanner;

public class Main {
    public static void print(QueueADT<Integer> myQueue){
        int s = myQueue.length();
        System.out.print("<");
        for(int i=1; i<=s; i++){
            Integer t = myQueue.dequeue();
            System.out.print(t+" ");
            myQueue.enqueue(t);
        }
        System.out.println(">");
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int s = sc.nextInt();
        //Integer[] arr = new Integer[s+1];
        QueueADT<Integer> myQueue = new LL<>(s);
        print(myQueue);
        while (true){
            int p,q;
            p = sc.nextInt();
            q = sc.nextInt();
            if(p==0)
                break;
            else if(p==1){
                myQueue.clear();
                print(myQueue);
                System.out.println(-1);
            }
            else if(p==2){
                myQueue.enqueue(q);
                print(myQueue);
                System.out.println(-1);
            }
            else if(p==3){
                Integer r = myQueue.dequeue();
                print(myQueue);
                System.out.println(r);
            }
            else if(p==4){
                int l = myQueue.length();
                print(myQueue);
                System.out.println(l);
            }
            else if(p==5){
                Integer r = myQueue.frontValue();
                print(myQueue);
                System.out.println(r);
            }
            else if(p==6){
                Integer r = myQueue.rearValue();
                print(myQueue);
                System.out.println(r);
            }
            else if(p==7){
                Integer r = myQueue.leaveQueue();
                print(myQueue);
                System.out.println(r);
            }
        }
    }
}
