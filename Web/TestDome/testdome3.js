/*
function formatDate(userDate) {
    // format from M/D/YYYY to YYYYMMDD
    var date = userDate.split('/')[2];
    if(userDate.split('/')[0].length == 1) date += '0' + userDate.split('/')[0];
    else date += userDate.split('/')[0]
    if(userDate.split('/')[1].length == 1) date += '0' + userDate.split('/')[1]; 
    else date += userDate.split('/')[1];
    return date;
  }
  
  console.log(formatDate("1/1/2014"));
  */
 function formatDate(userDate) { // format from M/D/YYYY to YYYYMMDD 
  var date=userDate.split('/'); 
  return date[2].concat(('0'+date[0]).slice(-2), ('0'+date[1]).slice(-2)); 
} 
console.log(formatDate("1/3/2014"));

