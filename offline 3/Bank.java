import java.util.Scanner;

class customer{
    int et,st,no;

    public customer(int et, int st,int no) {
        this.et = et;//entering time
        this.st = st;// service time
        this.no = no;//customer no
    }
}
public class Bank {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int s = sc.nextInt();
        QueueADT<customer> Queue1 = new LL<>(s);
        QueueADT<customer> Queue2 = new LL<>(s);
        int q1Time=0,q2Time=0;

        for(int i=1; i<=s; i++){
            int et = sc.nextInt();
            int st = sc.nextInt();
            customer t = new customer(et,st,i);
            if(Queue1.length()!=0){
               int f = Queue1.frontValue().et;
               if(q1Time>f)
                   f = q1Time + Queue1.frontValue().st;
               else
                   f+=Queue1.frontValue().st;
               while (f<=et){
                   customer c = Queue1.dequeue();
                   System.out.println("C"+c.no+" customer left q1 at "+f+"s");
                   q1Time = f;

                   int s1 = Queue2.length() - Queue1.length();
                   if(s1==2 && q1Time<et){
                       customer te = Queue2.leaveQueue();
                       Queue1.enqueue(te);
                       System.out.println("C"+te.no+" customer move q2 to q1 at "+q1Time+"s");
                   }

                   if(Queue1.length()!=0){
                       f = Queue1.frontValue().et;
                       if(q1Time>f)
                           f = q1Time + Queue1.frontValue().st;
                       else
                           f+=Queue1.frontValue().st;
                   }
                   else
                       break;
               }
            }
            if(Queue2.length()!=0){
                int f = Queue2.frontValue().et;
                if(q2Time>f)
                    f = q2Time + Queue2.frontValue().st;
                else
                    f+=Queue2.frontValue().st;
                while ( f<=et){
                    customer c =Queue2.dequeue();
                    System.out.println("C"+c.no+" customer left q2 at "+f+"s");
                    q2Time = f;

                    int s1 = Queue1.length() - Queue2.length();
                    if(s1==2 && q2Time<et){
                        customer te = Queue1.leaveQueue();
                        Queue2.enqueue(te);
                        System.out.println("C"+te.no+" customer move q1 to q2 at "+q2Time+"s");
                    }

                    if(Queue2.length()!=0){
                        f = Queue2.frontValue().et;
                        if(q2Time>f)
                            f = q2Time + Queue2.frontValue().st;
                        else
                            f+=Queue2.frontValue().st;
                    }
                    else{
                        break;
                    }
                }
            }
            if(Queue1.length()<= Queue2.length()){
                Queue1.enqueue(t);
                System.out.println("C"+t.no+" customer enter q1 at "+t.et+"s");
            }
            else{
                Queue2.enqueue(t);
                System.out.println("C"+t.no+" customer enter q2 at "+t.et+"s");
            }
        }
        if(Queue1.length() + Queue2.length()!=0){
            while (Queue1.length()+ Queue2.length()>0){
                if(Queue1.length()==0){
                    int f2 = Queue2.frontValue().et;
                    if(q2Time>f2)
                        f2 = q2Time + Queue2.frontValue().st;
                    else
                        f2+=Queue2.frontValue().st;
                    customer c = Queue2.dequeue();
                    System.out.println("C"+c.no+" customer left q2 at "+f2+"s");
                    q2Time = f2;
                }
                else if(Queue2.length()==0){
                    int f1 = Queue1.frontValue().et;
                    if(q1Time>f1)
                        f1 = q1Time + Queue1.frontValue().st;
                    else
                        f1+=Queue1.frontValue().st;
                    customer c = Queue1.dequeue();
                    System.out.println("C"+c.no+" customer left q1 at "+f1+"s");
                    q1Time = f1;
                }
                else{
                    int f1 = Queue1.frontValue().et;
                    if(q1Time>f1)
                        f1 = q1Time + Queue1.frontValue().st;
                    else
                        f1+=Queue1.frontValue().st;
                    int f2 = Queue2.frontValue().et;
                    if(q2Time>f2)
                        f2 = q2Time + Queue2.frontValue().st;
                    else
                        f2+=Queue2.frontValue().st;
                    if(f1<=f2){
                        customer c = Queue1.dequeue();
                        System.out.println("C"+c.no+" customer left q1 at "+f1+"s");
                        q1Time = f1;

                        int s1 = Queue2.length() - Queue1.length();
                        if(s1==2){
                            customer t = Queue2.leaveQueue();
                            Queue1.enqueue(t);
                            System.out.println("C"+t.no+" customer move q2 to q1 at "+f1+"s");
                        }
                    }
                    else{
                        customer c = Queue2.dequeue();
                        System.out.println("C"+c.no+" customer left q2 at "+f2+"s");
                        q2Time = f2;

                        int s1 = Queue1.length() - Queue2.length();
                        if(s1==2){
                            customer t = Queue1.leaveQueue();
                            Queue2.enqueue(t);
                            System.out.println("C"+t.no+" customer move q1 to q2 at "+f2+"s");
                        }
                    }
                }
            }
        }
        System.out.println("Booth 1 finishes service at t="+q1Time);
        System.out.println("Booth 2 finishes service at t="+q2Time);
    }
}
