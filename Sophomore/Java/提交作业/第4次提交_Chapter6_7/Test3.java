public class Test3 {
    public static int[][] createArray(int row){
        if(row <= 0){
            return null;
        }
        int[][] a = new int[row][];
        for(int i = 0; i < row; i++){
            a[i] = new int[row - i];
        }
        return a;
    }

    public static void printArray(int[][] a){
        if(a == null){
            System.out.println("null");
            return;
        }
        for(int i = 0; i < a.length; i++){
            for(int j = 0; j < a[i].length; j++){
                if(j > 0){
                    System.out.print(" ");
                }
                System.out.print(a[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        int[][] a = createArray(4);
        printArray(a);
    }
}
