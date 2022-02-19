import java.util.Scanner;

public class TNL {
    public static void task1(ListADT<Integer> RS, ListADT<Integer> BS, ListADT<Integer> TS){
        int s = RS.length();
        RS.moveToStart();
        for(int i=0; i<s; i++){
            int cur = RS.getValue();
            if(cur==i){
                if(i==s-1){
                    System.out.print(cur);
                }
                else{
                    System.out.print(cur+",");
                     RS.next();
                }
            }
            else if(i!=s-1){
                System.out.print(",");
            }
        }
        System.out.print("\n");

        BS.moveToStart();
        for(int i=0; i<s; i++){
            int cur = BS.getValue();
            if(cur==i){
                if(i==s-1){
                    System.out.print(cur);
                }
                else{
                    System.out.print(cur+",");
                    BS.next();
                }
            }
            else if(i!=s-1){
                System.out.print(",");
            }
        }
        System.out.print("\n");

        TS.moveToStart();
        for(int i=0; i<s; i++){
            int cur = TS.getValue();
            if(cur==i){
                if(i==s-1){
                    System.out.print(cur);
                }
                else{
                    System.out.print(cur+",");
                    TS.next();
                }
            }
            else if(i!=s-1){
                System.out.print(",");
            }
        }
        System.out.print("\n");
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int r,b,t;

        ///this line differ depending on array based list or linked list
        ListADT<Integer> RS  = new Arr<>();
        r = sc.nextInt();
        for(int i=0; i<r; i++){
            RS.append(i);
        }

        ///this line differ depending on array based list or linked list
        ListADT<Integer> BS  = new Arr<>();
        b = sc.nextInt();
        for(int i=0; i<b; i++){
            BS.append(sc.nextInt());
        }


        ///this line differ depending on array based list or linked list
        ListADT<Integer> TS  = new Arr<>();
        t = sc.nextInt();
        for(int i=0; i<t; i++){
            TS.append(sc.nextInt());
        }

        int n = sc.nextInt();
        task1(RS,BS,TS);
    }
}
