import java.util.HashSet;

public class FirstRepeatedString {

    //Time complexity : O(2N) where N is the number of words
    public static void main(String[] args) {
        String s = "Ravi had been saying that he had been there";

        String sset[] = s.split(" ");

        HashSet<String> seen = new HashSet<>();

        boolean yes = false;
        for (int i = 0; i < sset.length; i++) {
            if (seen.contains(sset[i])) {
                System.out.println("First repeated word: " + sset[i]);
                yes = true;
                break;
            }
            seen.add(sset[i]);
        }
        if (!yes) {
            System.out.println("No repeated word found!");
        }
    }
}