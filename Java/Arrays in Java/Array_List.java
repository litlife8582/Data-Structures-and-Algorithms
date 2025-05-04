import java.util.*;
public class Array_List {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        ArrayList num=new ArrayList();
        int n1=sc.nextInt();
        int n2=sc.nextInt();
        int n3=sc.nextInt();
        num.add(n1); 
        num.add(n2); //adds at the end of ArrayList
        num.add(1,n3); //The .add(a,b) --> a is the index and b is the element to be inserted 
        System.out.println(num);
        System.out.println(num.get(1));//Accessing Element
        //Traversing an ArrayList
        for(int i=0;i<num.size();i++){
            System.out.println(num.get(i));
        }
        //For ArrayList containing String
        String a=sc.next();
        String b=sc.next();
        String c=sc.next();
        ArrayList<String> StringList=new ArrayList<String>();
        StringList.add(a);
        StringList.add(b);
        StringList.add(c);
        for(String ele:StringList){
            System.out.println(ele);
        }
        //Traversing using Iterator method
        /**The Iterator in Java is a powerful interface used to traverse collections,
        such as lists and sets, allowing for sequential access to elements without exposing 
        the underlying structure of the collection. Here’s a detailed overview of its functionality,
        methods, and usage */
        Iterator<String> iterator=StringList.iterator();
        /** The Iterator interface includes several essential methods:
            1.hasNext(): Returns true if there are more elements to iterate over.
            2.next(): Returns the next element in the iteration. If no more elements are available, 
            it throws a NoSuchElementException.
            3.remove(): Removes the last element returned by the iterator from the underlying collection.
            This method can only be called after next() has been called.
            forEachRemaining(Consumer<? super E> action): Performs the given action for each remaining 
            element until all elements have been processed or an exception is thrown. **/
        while(iterator.hasNext())
        {
            String letter=iterator.next();
            System.out.println(letter);
        }

        //Searching for elements in an array
        ArrayList<String> str=new ArrayList<String>(Arrays.asList("a","b","c","d","e"));
        //For each method
        for(String ele:StringList){
            if(ele.equals("b")){
                System.out.println("The element is found");
            }
        }
        int n=StringList.indexOf(c);//Stores the index of teh element entered
        System.out.println(n);
        str.remove("c");//Removes element from the list
        System.out.println(str);
    }
}