package DSD.Failed;
import java.util.*;

public class QuineMcCluskey {

    static int n; // number of variables
    static ArrayList<Integer> minterms = new ArrayList<>();
    static ArrayList<Integer> dontcares = new ArrayList<>();

    static class Term {
        String bits;      // e.g. "10-1"
        Set<Integer> cover; // minterms covered
        boolean used;

        Term(String bits, Set<Integer> cover) {
            this.bits = bits;
            this.cover = new HashSet<>(cover);
            this.used = false;
        }
    }

    public static void main(String[] args) {
        Scanner hv = new Scanner(System.in);
        System.out.print("How many Variables (2<=n<=6)? --> ");
        n = hv.nextInt();

        System.out.print("\nHow many Minterms? : ");
        int mCount = hv.nextInt();
        System.out.println("Enter Minterms (space separated):");
        for (int i = 0; i < mCount; i++) {
            minterms.add(hv.nextInt());
        }

        System.out.print("\nHow many Don't-Cares? : ");
        int dCount = hv.nextInt();
        if (dCount > 0) {
            System.out.println("Enter Don't-Cares (space separated):");
            for (int i = 0; i < dCount; i++) {
                dontcares.add(hv.nextInt());
            }
        }

        // QM algorithm
        ArrayList<Term> primes = generatePrimeImplicants();
        ArrayList<Term> essentials = findEssentialPrimeImplicants(primes);

        // display answer
        System.out.println("\nSimplified SOP Expression:");
        for (int i = 0; i < essentials.size(); i++) {
            System.out.print(bitsToExpr(essentials.get(i).bits));
            if (i != essentials.size() - 1) System.out.print(" + ");
        }
        System.out.println();
        hv.close();

    }

    // Generate prime implicants
    static ArrayList<Term> generatePrimeImplicants() {
        ArrayList<Term> terms = new ArrayList<>();
        for (int m : minterms) {
            terms.add(new Term(toBinary(m, n), Set.of(m)));
        }
        for (int d : dontcares) {
            terms.add(new Term(toBinary(d, n), Set.of(d)));
        }

        ArrayList<Term> primes = new ArrayList<>();
        boolean combined;

        do {
            combined = false;
            ArrayList<Term> newTerms = new ArrayList<>();

            for (int i = 0; i < terms.size(); i++) {
                for (int j = i + 1; j < terms.size(); j++) {
                    String merged = merge(terms.get(i).bits, terms.get(j).bits);
                    if (merged != null) {
                        combined = true;
                        terms.get(i).used = true;
                        terms.get(j).used = true;

                        Set<Integer> union = new HashSet<>(terms.get(i).cover);
                        union.addAll(terms.get(j).cover);

                        Term t = new Term(merged, union);
                        if (!contains(newTerms, t)) {
                            newTerms.add(t);
                        }
                    }
                }
            }

            for (Term t : terms) {
                if (!t.used && !contains(primes, t)) {
                    primes.add(t);
                }
            }

            terms = newTerms;

        } while (combined);

        for (Term t : terms) {
            if (!contains(primes, t)) {
                primes.add(t);
            }
        }

        return primes;
    }

    // Find essential prime implicants
    static ArrayList<Term> findEssentialPrimeImplicants(ArrayList<Term> primes) {
        ArrayList<Term> essentials = new ArrayList<>();

        for (int m : minterms) {
            ArrayList<Term> covers = new ArrayList<>();
            for (Term t : primes) {
                if (t.cover.contains(m)) {
                    covers.add(t);
                }
            }
            if (covers.size() == 1) {
                Term only = covers.get(0);
                if (!essentials.contains(only)) {
                    essentials.add(only);
                }
            }
        }
        return essentials;
    }

    // all helper functions
    static String toBinary(int num, int len) {
        String s = Integer.toBinaryString(num);
        while (s.length() < len) s = "0" + s;
        return s;
    }

    static String merge(String a, String b) {
        int diff = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i)) {
                sb.append(a.charAt(i));
            } else {
                sb.append('-');
                diff++;
            }
            if (diff > 1) return null;
        }
        return sb.toString();
    }

    static boolean contains(ArrayList<Term> list, Term t) {
        for (Term x : list) {
            if (x.bits.equals(t.bits)) return true;
        }
        return false;
    }

    static String bitsToExpr(String bits) {
        StringBuilder sb = new StringBuilder();
        char var = 'A';
        for (int i = 0; i < bits.length(); i++) {
            if (bits.charAt(i) == '1') sb.append(var);
            else if (bits.charAt(i) == '0') sb.append(var).append('\'');
            var++;
        }
        if (sb.length() == 0) return "1"; // covers all
        return sb.toString();
    }
}
