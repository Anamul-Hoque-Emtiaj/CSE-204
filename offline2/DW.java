import java.util.Scanner;

class Dish{
    int k,t,s,f;

    public Dish(int k, int t, int s) {
        this.k = k;
        this.t = t;
        this.s = s;
    }
}

public class DW {
    public static  void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n,x;
        n = sc.nextInt();
        x = sc.nextInt();
        int[] time = new int[x+1];
        for(int i=1; i<=x; i++){
            time[i] = sc.nextInt();
        }

        /*
        //Using Arr implementation of stacks
        StackADT<Dish> dStack = new Arr<>();
        StackADT<Dish> cStack = new Arr<>();
        StackADT<Integer> dishComplete = new Arr<>();
        */

        /*
        //Using LL implementation of stacks
        StackADT<Dish> dStack = new LL<>();
        StackADT<Dish> cStack = new LL<>();
        StackADT<Integer> dishComplete = new LL<>();
        */

        //*
        // Using 1 Array 2 Stack implementation of stacks
        Dish[] arr = new Dish[n*x];
        StackADT<Dish> dStack = new Arr<>(arr,n*x,1);
        StackADT<Dish> cStack = new Arr<>(arr,n*x,-1);
        StackADT<Integer> dishComplete = new Arr<>();
        //*/

        int passedTime = -1;
        while (true){
            int k,t,s;
            k = sc.nextInt();
            t = sc.nextInt();
            s = sc.nextInt();
            Dish d = new Dish(k,t,s);
            if(k==0)
                break;

            if(s==x)
                dishComplete.push(k);
            if(passedTime>t){///cleaning in progress...keeping the disk in dirty disks stack
                dStack.push(d);
            }
            else if(passedTime==t){/// took it immediately
                passedTime += time[s];
                d.f = passedTime;
                cStack.push(d);
            }
            else if(passedTime<t){
                if(dStack.length()==0){
                    passedTime = t + time[s]-1;
                    d.f = passedTime;
                    cStack.push(d);
                }
                else{
                    while (passedTime<t && dStack.length()>0){
                        Dish d1 = dStack.pop();
                        if(d1.t<=passedTime){
                            passedTime += time[d1.s];
                            d1.f = passedTime;
                            cStack.push(d1);
                        }else {
                            passedTime = d1.t + time[d1.s]-1;
                            d1.f = passedTime;
                            cStack.push(d1);
                        }
                    }
                    dStack.push(d);
                }

            }
        }
        while (dStack.length()!=0){
            Dish d1 = dStack.pop();
            if(d1.t<=passedTime){
                passedTime += time[d1.s];
                d1.f = passedTime;
                cStack.push(d1);
            }else {
                passedTime = d1.t + time[d1.s]-1;
                d1.f = passedTime;
                cStack.push(d1);
            }
        }
        System.out.println(passedTime);
        int[] temp = new int[cStack.length()];
        int i=0;
        while (cStack.length()!=0){
            temp[i++] = cStack.pop().f;
        }
        for(i = temp.length-1; i>=1; i--)
            System.out.print(temp[i]+",");
        System.out.println(temp[0]);
        if(dishComplete.length()==n)
            System.out.println("Y");
        else
            System.out.println("N");
        while (dishComplete.length()!=1){
            System.out.print(dishComplete.pop()+",");
        }
        System.out.print(dishComplete.pop());
    }
}
