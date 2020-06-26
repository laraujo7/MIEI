import java.time.LocalDate;
import java.time.LocalTime;


public class ArrayLocalDate {

    private LocalDate[] datas;

    public ArrayLocalDate(int n){
        datas = new LocalDate[n];
    }

    public void insereData(LocalDate data, int i){
        this.datas[i] = data;
    }

    public LocalDate getData(int i){
        return this.datas[i];
    }


    public LocalDate dataMaisProxima(LocalDate data){
        int i,menor = Integer . MAX_VALUE;
        LocalDate res = LocalDate.now();

        for(i = 0 ; i<this.datas.length ; i++){
            if(Math.abs(this.datas[i].compareTo(data)) < menor) res = this.datas[i];

        }

        return res;
    }


}
