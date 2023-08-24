class Solution {
    public static List<String> fullJustify(String[] words, int maxWidth) {
        int start = 0;
        int count = 1;
        int end = 1;
        int size = words[0].length();
        List<String> res = new LinkedList<>();
        while(end<=words.length){
            if(end!=words.length&&words[end].length()+size+count<=maxWidth){
                size+=words[end].length();
                end++;
                count++;
            }else{
                StringBuilder sb = new StringBuilder();
                int gap = count==1?0:(maxWidth-size)/(count-1);
                int extraGap = count==1?0:(maxWidth-size)%(count-1);
                for(int i=start;i<end;i++){
                    sb.append(words[i]);
                    if(i+1!=end){
                        if(end<words.length){
                            for(int g=0;g<gap;g++)
                                sb.append(" ");
                            if(0<extraGap)sb.append(" ");
                            extraGap--;
                        }else sb.append(" ");
                        
                    }
                }
                while(sb.length()<maxWidth){
                    sb.append(" ");
                }
                res.add(sb.toString());
                start = end;
                count = 0;
                size = 0;
                if(end==words.length)break;
            }
        }
        return res;
    }
}
