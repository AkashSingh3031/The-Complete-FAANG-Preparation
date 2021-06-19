package server

import (
	"encoding/json"
	"fmt"
	"net/http"
)
type Department struct{
	DeptId string;
	DeptName string;
	DeptDescription string; 
}
var depts []Department;
func GetDepartmentEndPoint(w http.ResponseWriter, req *http.Request){
	rows,er:=db.Query("select * from department");
    fmt.Println(rows)
	depts:=[]Department{};
      if(er==nil){
         var temp=Department{}
         for rows.Next(){
            rows.Scan(&temp.DeptId,&temp.DeptName,&temp.DeptDescription);
            depts=append(depts,temp);
         }
      }
	  json.NewEncoder(w).Encode(depts)
}
func DelteDepartmentEndPoint(w http.ResponseWriter, req *http.Request){
	var p Department
    err := json.NewDecoder(req.Body).Decode(&p)
    if err != nil {
        http.Error(w, err.Error(), http.StatusBadRequest)
        return
    }
	rows,er:=db.Query("DELETE FROM `department` where dept_id="+p.DeptId);
	if(er==nil){
		fmt.Fprintf(w,"Success");
	}else{
		_=rows
		fmt.Fprintf(w,"Failed");
	}
 
}
func AddDepartmentEndPoint(w http.ResponseWriter, req *http.Request){
	var k Department
	err:=json.NewDecoder(req.Body).Decode(&k);
	if(err!=nil){
		http.Error(w, err.Error(), http.StatusBadRequest)
        return
	}
	if(k.DeptName!=""){
	rows,err:=db.Query("INSERT INTO department (dept_name,dept_description) VALUES('"+k.DeptName+"','"+k.DeptDescription+"'"+")");
	if(err!=nil){
		_=rows
		var reserr Error
		reserr = SetError(reserr, "Department Not Added");
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
		reserr = SetError(reserr, "Name cannot be Empty");
		json.NewEncoder(w).Encode(reserr);
		return 
	}
}