package SingleNumber;

import java.util.HashMap;
import java.util.Map;

public class SingleNumber
{

    public int singleNumber(int[] A) {

        Map<Integer, Integer> hm = new HashMap<Integer, Integer>();
        int result = 0;
        for (int i : A) {
            if(hm.get(i) == null){
                hm.put(i, 1);
            }else{
                hm.remove(i);
            }
        }
        for(Map.Entry<Integer, Integer> entry : hm.entrySet()){
            result = entry.getKey();
        }
        
        return result;

    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int[] a = {1,1,2,2,3,4,4};
        SingleNumber s = new SingleNumber();
        System.out.print(s.singleNumber(a));
    }

}
