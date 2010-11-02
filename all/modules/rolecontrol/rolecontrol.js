// $Id$

function DoToAll(obj_input){

bol_is_checked = (obj_input.checked)?true:false

for (x=0;x<obj_input.form.length;x++){
        if (!(obj_input.form.elements[x].disabled)){
		obj_input.form.elements[x].checked = bol_is_checked;
	  }
    }
}