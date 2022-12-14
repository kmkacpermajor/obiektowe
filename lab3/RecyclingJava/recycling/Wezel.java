package lab3.RecyclingJava.recycling;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Scanner;
import java.util.Map;
import java.util.Arrays;

// zad5: Nie
// zad6: Tak
// zad11: Powstałe odniesienia nie są silne, więc Java uznaje, że w wypadku braku miejsca w pamięci można usunąć te obiekty 
// zad12: Bo musielibyśmy z góry określić ilość połączeń


public class Wezel {
    ArrayList<Wezel> polaczenia = new ArrayList<>();

    protected void dodajPolaczenie(Wezel doPolaczenia){
        polaczenia.add(doPolaczenia);
    } 

    protected boolean sprawdzPolaczenieHashMap(Wezel doPolaczenia){
        HashMap<Wezel, Boolean> polaczeniaHashMap = new HashMap<>();

        for (Wezel wezel : polaczenia){
            polaczeniaHashMap.put(wezel, true);
        }

        if(polaczeniaHashMap.containsKey(doPolaczenia)){
            return true;
        }

        return false;
    }

    protected boolean sprawdzPolaczenieTreeMap(Wezel doPolaczenia){
        TreeMap<Wezel, Boolean> polaczeniaTreeMap = new TreeMap<>();

        for (Wezel wezel : polaczenia){
            polaczeniaTreeMap.put(wezel, true);
        }

        if(polaczeniaTreeMap.containsKey(doPolaczenia)){
            return true;
        }

        return false;
    }

    protected void finalize() throws Throwable{
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        for (int i=0; i<=1000000; i++){
            Wezel w1 = new Wezel ();
            Wezel w2 = new Wezel ();
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);
        }
        s.nextLine();
        s.close();
    }
}