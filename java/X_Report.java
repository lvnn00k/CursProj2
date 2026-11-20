package shift;

public class X_Report extends BaseReport {
    private static int count = 0;

    public static int getCount()
    {
        return ++count;
    }

    public static void resetCount()
    {
        count = 0;
    }

    @Override 
    public String getName()
    {
        return "X-отчет\t№" + getCount() + "\n";
    }
}

