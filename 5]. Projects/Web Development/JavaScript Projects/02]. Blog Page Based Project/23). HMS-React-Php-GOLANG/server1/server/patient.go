package server

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"net/http"

	_ "github.com/go-sql-driver/mysql"
)
type Patient struct{
	Id string 
	Name string 
	Email string 
	Password string
	Address string 
	Phone string 
	Sex string
	BirthDate string
	Age string
	BloodGroup string
}
var db *sql.DB
var pat []Patient
func createConnection(){
	DB,err:=sql.Open("mysql", "root:password1234@tcp(172.17.0.2)/hospital");
	if(err!=nil){
		panic(err);
	}
	db=DB;
}
func GetPatientEndPoint(w http.ResponseWriter, req *http.Request){
	(w).Header().Set("Access-Control-Allow-Origin", "*")
	(w).Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
	if req.Header.Get("Role") != "admin" {
		w.Write([]byte("Not authorized."))
		return ;
	}else{
	rows,er:=db.Query("select patient_id,patient_name,email,address,phone,sex from patient");
    fmt.Println(rows)
	pat:=[]Patient{};
      if(er==nil){
         var temp=Patient{}
         for rows.Next(){

            rows.Scan(&temp.Id,&temp.Name,&temp.Email,&temp.Address,&temp.Phone,&temp.Sex);
           
            pat=append(pat,temp);
         }
      }
	  json.NewEncoder(w).Encode(pat)
	}
}


func DeletePatientEndPoint(w http.ResponseWriter, req *http.Request){
	var p Patient
    err := json.NewDecoder(req.Body).Decode(&p)
    if err != nil {
        http.Error(w, err.Error(), http.StatusBadRequest)
        return
    }
	fmt.Println("Hi");
	fmt.Println(p);
	rows,er:=db.Query("DELETE FROM `patient` where patient_id="+p.Id);
	if(er==nil){
		fmt.Fprintf(w,"Success");
	}else{
		_=rows
		fmt.Fprintf(w,"Failed");
	}
    fmt.Fprintf(w, "Person: %+v", p)

}
func AddPatientEndPoint(w http.ResponseWriter, req *http.Request){
	var k Patient

	err:=json.NewDecoder(req.Body).Decode(&k);
	if(err!=nil){
		http.Error(w, err.Error(), http.StatusBadRequest)
        return
	}
	fmt.Println("this is k");
	fmt.Println(k);
	if(k.Name!=""&&k.Email!=""&&k.Password!=""){
		if(isValid(k.Password)){
			rows,err:=db.Query("INSERT INTO `patient`(`patient_name`,`email`,`password`,`address`,`phone`,`sex`,`birthdate`,`age`,`blood_group`) VALUES('"+k.Name+"','"+k.Email+"','"+k.Password+"','"+k.Address+"','"+k.Phone+"','"+k.Sex+"','"+k.BirthDate+"','"+k.Age+"','"+k.BloodGroup+"')");
			if(err!=nil){
				_=rows
				fmt.Println(err);
				var reserr Error
				reserr = SetError(reserr, "Doctor Not Added");
				json.NewEncoder(w).Encode(reserr);
				return 
			}
			if(err==nil){
					fmt.Fprintf(w,"Success");
			}else{
				_=rows
				fmt.Fprintf(w,"Failed");
			}
		}else{
			var reserr Error
			reserr = SetError(reserr, "Password Doesnot Follow The Constraints");
			json.NewEncoder(w).Encode(reserr);
			return 
		}
	}else{
		var reserr Error
		reserr = SetError(reserr, "Mandatory Field Cannot be empty");
		json.NewEncoder(w).Encode(reserr);
		return 
	}
}