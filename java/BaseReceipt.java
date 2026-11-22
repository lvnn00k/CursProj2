package receipt;

public abstract class BaseReceipt {
    public abstract void show();
    public abstract double getSum();
    public abstract int getTypeID();
    public abstract void addNewItem();
    public abstract void deleteItem();
}