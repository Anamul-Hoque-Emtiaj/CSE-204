import java.util.Scanner;

public class Main {
    public static void print(ListADT<Integer> arr){
        int cp = arr.currPos();
        int s = arr.length();
        arr.moveToStart();
        System.out.print("<");
        for(int i=0; i<s; i++){
            if(i==cp){
                System.out.print("| ");
                System.out.print(arr.getValue()+" ");
            }
            else{
                System.out.print(arr.getValue()+" ");
            }
            arr.moveToPos(i+1);
        }
        System.out.println(">");
        arr.moveToPos(cp);
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int K,X;
        K = sc.nextInt();
        X = sc.nextInt();

        ///have to change this line if the list is not an integer list
        Integer[] a = new Integer[K];
        for(int i=0; i<K; i++){
            a[i] = sc.nextInt();
        }
        ///have to change this line if the list is not an integer list
        ///this line differ depending on array based list or linked list
        ListADT<Integer> arr  = new Arr<>(a,K,X);
        print(arr);
        while (true){
            int Q;
            ///have to change this line if the list is not an integer list
            Integer P;
            Q = sc.nextInt();
            P = sc.nextInt();
            if(Q==0)
                break;
            else if(Q==1) {
                arr.clear();
                print(arr);
                System.out.println(-1);
            }
            else if(Q==2){
                arr.insert(P);
                print(arr);
                System.out.println(-1);
            }
            else if(Q==3){
                arr.append(P);
                print(arr);
                System.out.println(-1);
            }
            else if(Q==4){
                ///have to change this line if the list is not an integer list
                Integer t = arr.remove();
                print(arr);
                System.out.println(t);
            }
            else if(Q==5){
                arr.moveToStart();
                print(arr);
                System.out.println(-1);
            }
            else if(Q==6){
                arr.moveToEnd();
                print(arr);
                System.out.println(-1);
            }
            else if(Q==7){
                arr.prev();
                print(arr);
                System.out.println(-1);
            }
            else if(Q==8){
                arr.next();
                print(arr);
                System.out.println(-1);
            }
            else if(Q==9){
                int s = arr.length();
                print(arr);
                System.out.println(s);
            }
            else if(Q==10){
                int s = arr.currPos();
                print(arr);
                System.out.println(s);
            }
            else if(Q==11){
                arr.moveToPos(P);
                print(arr);
                System.out.println(-1);
            }
            else if(Q==12){
                ///have to change this line if the list is not an integer list
                Integer v = arr.getValue();
                print(arr);
                System.out.println(v);
            }
            else if(Q==13){
                int i = arr.Search(P);
                print(arr);
                System.out.println(i);
            }
        }
    }
}
