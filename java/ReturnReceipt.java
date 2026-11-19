package receipt;

public final class ReturnReceipt extends BaseReceipt {
    private double sum;

    public ReturnReceipt(double receiptSum)
    {
        sum = receiptSum;
    }

    @Override 
    public void show()
    {
        System.out.printf("Возврат прихода:\t%f \n", sum);
    }

    @Override 
    public double getSum()
    {
        return sum;
    }

    @Override 
    public int getTypeID()
    {
        return 0;
    }

    @Override 
    public void deleteItem()
    {
        return;
    }

    @Override 
    public void addNewItem()
    {
        return;
    }
}