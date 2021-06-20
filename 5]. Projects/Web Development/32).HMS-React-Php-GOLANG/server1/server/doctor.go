package server

import (
	"encoding/json"
	"fmt"
	"net/http"
)
type doctor struct{
	Id string 
	Name string
	Email string
	Password string
	Address string
	Phone string  
	Department string 
}

var doc []doctor

func GetDoctorEndPoint(w http.ResponseWriter, req *http.Request){
	rows,er:=db.Query("SELECT doctor_id,doctor_name,department FROM `doctor`");
	doc:=[]doctor{};
	if(er==nil){
		
		var temp doctor
		for rows.Next(){
            rows.Scan(&temp.Id,&temp.Name,&temp.Department);
           
            doc=append(doc,temp);
         }
	}
	json.NewEncoder(w).Encode(doc);
}
func DeleteDoctorEndPoint(w http.ResponseWriter, req *http.Request){
	var p doctor
    err := json.NewDecoder(req.Body).Decode(&p)
    if err != nil {
        http.Error(w, err.Error(), http.StatusBadRequest)
        return
    }
	rows,er:=db.Query("DELETE FROM `doctor` where doctor_id="+p.Id);
	if(er==nil){
		fmt.Fprintf(w,"Success");
	}else{
		_=rows
		fmt.Fprintf(w,"Failed");
	}
   

}
func AddDoctorEndPoint(w http.ResponseWriter, req *http.Request){
	var k doctor

	err:=json.NewDecoder(req.Body).Decode(&k);
	if(err!=nil){
		http.Error(w, err.Error(), http.StatusBadRequest)
        return
	}
	if(k.Name!=""&&k.Email!=""&&k.Password!=""){
		if(isValid(k.Password)){
			rows,err:=db.Query("INSERT INTO `doctor`(`doctor_name`, `email`, `password`, `address`, `phone`, `department`) VALUES('"+k.Name+"','"+k.Email+"','"+k.Password+"','"+k.Address+"','"+k.Phone+"','"+k.Department+"')");
			if(err!=nil){
				_=rows
				fmt.Println(err);
				var reserr Error
				reserr = SetError(reserr, "Doctor Not Added");
				json.NewEncoder(w).Encode(reserr);
				return 
			}else{
				fmt.Fprintf(w,"Success");
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
func DocAppointmentEndPoint(w http.ResponseWriter, req *http.Request){
	var app []appointment;
	var k doctor
	err:=json.NewDecoder(req.Body).Decode(&k);
	fmt.Println(k);
	if(err==nil){
		rows,er:=db.Query("select name,description,day,contact,apid from appointment a,doctor d where a.id=d.doctor_id and d.doctor_id='"+k.Id+"'");
		// fmt.Println("select  from appointment a,doctor d where a.id=d.doctor_id and d.doctor_id='"+k.Id+"'");
		if(er==nil){
			var temp appointment
			for rows.Next(){
				rows.Scan(&temp.Name,&temp.Description,&temp.Day,&temp.Contact,&temp.Apid);
				app=append(app,temp);
			}
			
		}
		json.NewEncoder(w).Encode(app);
	}else{
		var reserr Error
		reserr = SetError(reserr, "Failed To Fetch Appointments");
		json.NewEncoder(w).Encode(reserr);
		return 
	}
}
func GetPrescription(w http.ResponseWriter, req *http.Request){
	var temp appointment
	err:=json.NewDecoder(req.Body).Decode(&temp);
	if(err==nil){
		rows,er:=db.Query("update appointment set prescription='"+temp.Prescription+"' where apid='"+temp.Apid+"'");
		
		if(er==nil){
			_=rows;
			fmt.Fprintf(w,"Success")
			
		}else{
		fmt.Fprintf(w,"Failed");
		}
	}else{
		var reserr Error
		reserr = SetError(reserr, "Failed To Fetch Appointments");
		json.NewEncoder(w).Encode(reserr);
		return
	}

}