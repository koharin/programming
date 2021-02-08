function createCheckDigit(membershipId) {
  // Write the code that goes here.
  if(membershipId.length === 1) return membershipId;
  while(membershipId.length != 1){
    let Sum = 0;
    for(value of membershipId) Sum += parseInt(value);
    membershipId = Sum + '';
  }
  return membershipId;
}

console.log(createCheckDigit("55555"));