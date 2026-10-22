package receipt;

class ReceiptItem implements AutoCloseable {
    private Product product;
    private int amount;
    private double sum;

    

    public ReceiptItem(Product product, int amount) 
    {
        this.product = product;
        this.amount = amount;
        this.sum = amount*getPrice();
    }

    public double getPrice() 
    {
        return product.getPrice();
    }

    public double getNds() 
    {
        return product.getNds();
    }

    public String getName()
    {
        return product.getName();
    }

    public int getAmount() 
    {
        return amount;
    }

    public double getSum() 
    {
        return  sum;
    }

    public void newAmount(int amount) 
    {
        this.amount = amount;
        this.sum = amount*getPrice();
    }

    @Override
    public void close() 
    {
        System.out.println("Позация чека удалена");
    }

    public String toString() 
    {
        return product + "*" + amount + "\t" + sum;
    }
}