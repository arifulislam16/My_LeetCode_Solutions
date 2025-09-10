class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int b=0,e=letters.length-1;
        while(b<=e){
            int mid=b+(e-b)/2;
            if(letters[mid]>target){e=mid-1;}
            else{b=mid+1;}
        }
        if(b>=letters.length){return letters[0];}
        return letters[b];
    }
}