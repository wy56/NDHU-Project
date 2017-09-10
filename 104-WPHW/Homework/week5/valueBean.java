package beanLib;

public class valueBean{
    private int price, number, totalValue;

    public void setPrice(int p){
        this.price = p;
    }
    
    public void setNumber(int n){
        this.number = n;
    }
    
    public int getPrice(){
        return this.price;
    }
    
    public int getNumber(){
        return this.number;
    }
    
    public int gettotalValue(){
        totalValue = price*number;
        return totalValue;
    } 
}
