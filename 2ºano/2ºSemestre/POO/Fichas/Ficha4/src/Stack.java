import java.util.ArrayList;

public class Stack {

    private ArrayList<String> stack;

    public Stack(){
        this.stack = new ArrayList<String>();
    }

    public Stack(ArrayList<String> s){
        this.stack = s;
    }

    public Stack(Stack s){
        this.stack = s.getArrayList();
    }

    public ArrayList<String> getArrayList(){
        return this.stack;
    }

    public String top(){
        return this.stack.get(this.stack.size()-1);
    }

    public void push(String s){
        this.stack.add(s);
    }

    public void pop(){
        if(!this.stack.isEmpty()) this.stack.remove(this.stack.size()-1);
    }

    public boolean empty(){
        return this.stack.isEmpty();
    }

    public int length(){
        return this.stack.size();
    }


}
