package receipt;

import java.util.List;

class Product implements AutoCloseable {
    private String name;
    private double price;
    private int nds;

    public Product(String name, double price, int nds) 
    {
        this.name = name;
        this.price = price;
        this.nds = nds;
    }

    public String getName() 
    {
        return name;
    }

    public double getPrice() 
    {
        return price;
    }

    public int getNds() 
    {
        return nds;
    }

    @Override
    public void close() 
    {
        System.out.println("Продукт удален");
    }

    public String toString()
    {
        return name + "\t" + price;
    }
} 

class Products {

    public static final List<Product> array = List.of(
        new Product("one", 100.00, 22),
        new Product("two", 200.00, 0),
        new Product("three", 300.00, 22)
    );

}