import java.util.List;
import java.util.ArrayList;
import static java.lang.Integer.parseInt;

public class schedule{

    private List<List<String>> meetings;
    private List<String> limits;
    private int period;

    public schedule(List<List<String>> meetings, List<String> limits){
        this.meetings = new ArrayList<>(meetings);
        this.limits = new ArrayList<>(limits);
    }
    public void setperiod(int period){this.period = period;}
    public int getperiod(){return this.period;}

    public List<String> betweenmeetings(List<String> time,List<String> time2){
        if(time.get(1).equals(time2.get(0))) return null;
        List<String> parts = new ArrayList<>();
        for(String s:time){
            String[] partes = s.split(":");
            parts.add(partes[0]);
            parts.add(partes[1]);
        }
        for(String s:time2){
            String[] partes = s.split(":");
            parts.add(partes[0]);
            parts.add(partes[1]);
        }
        List<String> res = new ArrayList<>();
        res.add(parts.get(2)+":"+parts.get(3));
        res.add(parts.get(4)+":"+parts.get(5));
        return res;
    }

    public List<List<String>> betweenmeetinggeral(List<List<String>> time){
        List<List<String>> res = new ArrayList<>();
        for(int i = 0;i<time.size()-1;i++){
            res.add(betweenmeetings(time.get(i),time.get(i+1)));
        }
        return res;
    }

    public int timebetweenmeetings(List<String> time){
        List<String> parts = new ArrayList<>();
        for(String s:time){
            String[] partes = s.split(":");
            parts.add(partes[0]);
            parts.add(partes[1]);
        }
        return (parseInt(parts.get(2))-parseInt(parts.get(0))*60 + parseInt(parts.get(2))-parseInt(parts.get(1)));
    }

    public boolean timetomeet(List<String> time){
        return timebetweenmeetings(time)<=this.period;
    }

    void main(String[] args){
        List<String> p1a = new ArrayList<>();
        List<String> p1b = new ArrayList<>();
        List<String> p1c = new ArrayList<>();
        List<String> p1d = new ArrayList<>();
        p1a.add("9:00");
        p1a.add("10:30");
        p1b.add("12:00");
        p1b.add("13:00");
        p1c.add("16:00");
        p1c.add("18:00");
        p1d.add("9:00");
        p1d.add("20:00");
        List<List<String>> p1 = new ArrayList<>();
        p1.add(p1a); p1.add(p1b); p1.add(p1c);
        schedule person1 = new schedule(p1,p1d);

        List<String> p2a = new ArrayList<>();
        List<String> p2b = new ArrayList<>();
        List<String> p2c = new ArrayList<>();
        List<String> p2d = new ArrayList<>();
        List<String> p2e = new ArrayList<>();
        p2a.add("10:00");
        p2a.add("11:30");
        p2b.add("12:30");
        p2b.add("14:30");
        p2c.add("14:30");
        p2c.add("15:00");
        p2d.add("16:00");
        p2d.add("17:00");
        p2e.add("10:00");
        p2e.add("18:30");

        List<List<String>> p2 = new ArrayList<>();
        p2.add(p2a); p2.add(p2b); p2.add(p2c); p2.add(p2d);
        schedule person2 = new schedule(p2,p2e);

        person1.setperiod(30); person2.setperiod(30);

    }

}

/*
    [["9:00","10:30"],["12:00",13:00],["16:00","18:00"]] 3
    ["9:00","20:00"]

    [["10:00","11:30"],["12:30","14:30"],["14:30","15:00"],["16:00","17:00"]] 4
    ["10:00","18:30"]

    30 min

    res: [["11:30","12:00"],["15:00,"16:00"],["18:00","18:30"]]
 */


