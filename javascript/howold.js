function diff_years(dt2, dt1){

    var diff =(dt2.getTime() - dt1.getTime()) / 1000;
    diff /= (60 * 60 * 24);
    if((dt2.getUTCMonth() == dt1.getUTCMonth() ^ dt2.getUTCDay() < dt1.getUTCDay()) || (dt2.getUTCMonth() < dt1.getUTCMonth())) return Math.abs(Math.round(diff/365.25)-1);

    return Math.abs(Math.round(diff/365.25));
}

dt1 = new Date(2014,10,2);
dt2 = new Date(2014,10,11);
console.log(diff_years(dt1, dt2));

dt1 = new Date(2002,10,13);
dt2 = new Date(Date.now());
console.log(diff_years(dt1, dt2));
