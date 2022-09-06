function diff_years(dt2, dt1){

    var diff =(dt2.getTime() - dt1.getTime()) / 1000;
    diff /= (60 * 60 * 24);
    if((dt2.getUTCMonth() == dt1.getUTCMonth() ^ dt2.getUTCDay() < dt1.getUTCDay()) || (dt2.getUTCMonth() < dt1.getUTCMonth())) return Math.abs(Math.round(diff/365.25)-1);

    return Math.abs(Math.round(diff/365.25));
}
