package server

import (
	"encoding/json"
	"fmt"
	"net/http"
)
type appointment struct{
	Name string
	Description string
	Day string 
	Contact string
	Apid string
	Prescription string
	Id string
	Speciality string
	Email string
	Age string
}
func AddAppointment(w http.ResponseWriter, req *http.Request){
	var temp appointment
	err:=json.NewDecoder(req.Body).Decode(&temp);
	if(err==nil){
		rows,er:=db.Query("INSERT INTO appointment VALUES(DEFAULT,'"+temp.Name+"','"+temp.Email+"','"+temp.Contact+"' ,"+temp.Age+" ,'"+temp.Day+"','"+temp.Speciality+"','"+temp.Description+"','"+temp.Id+"','')")
		if(er==nil){
			_=rows
			fmt.Fprintf(w,"Success");
		}else{
			fmt.Println(er);
			fmt.Fprintf(w,"Failed");
		}
	}
}
func PatientAppointment(w http.ResponseWriter, req *http.Request){
	var temp appointment
	var res=[]appointment{};
	err:=json.NewDecoder(req.Body).Decode(&temp)
	if(err==nil){
		rows,er:=db.Query("select name,prescription,email,apid from appointment a where a.email='"+temp.Email+"'");
		if(er==nil){
			var k appointment
			for rows.Next(){
				rows.Scan(&k.Name,&k.Prescription,&k.Email,&k.Apid);
				res=append(res, k)
			}
			json.NewEncoder(w).Encode(res);
		}else{
			fmt.Fprintf(w,"Failed");
		}
	}
}