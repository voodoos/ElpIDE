parcelRequire=function(e,r,n,t){function i(n,t){function o(e){return i(o.resolve(e))}function c(r){return e[n][1][r]||r}if(!r[n]){if(!e[n]){var l="function"==typeof parcelRequire&&parcelRequire;if(!t&&l)return l(n,!0);if(u)return u(n,!0);if(f&&"string"==typeof n)return f(n);var p=new Error("Cannot find module '"+n+"'");throw p.code="MODULE_NOT_FOUND",p}o.resolve=c;var a=r[n]=new i.Module(n);e[n][0].call(a.exports,o,a,a.exports,this)}return r[n].exports}function o(e){this.id=e,this.bundle=i,this.exports={}}var u="function"==typeof parcelRequire&&parcelRequire,f="function"==typeof require&&require;i.isParcelRequire=!0,i.Module=o,i.modules=e,i.cache=r,i.parent=u;for(var c=0;c<n.length;c++)i(n[c]);if(n.length){var l=i(n[n.length-1]);"object"==typeof exports&&"undefined"!=typeof module?module.exports=l:"function"==typeof define&&define.amd?define(function(){return l}):t&&(this[t]=l)}return i}({682:[function(require,module,exports) {
"use strict";Object.defineProperty(exports,"__esModule",{value:!0});var E=exports.conf={comments:{lineComment:"//",blockComment:["/*","*/"]},brackets:[["[","]"],["(",")"],["{","}"]],autoClosingPairs:[{open:'"',close:'"',notIn:["string","comment"]},{open:"'",close:"'",notIn:["string","comment"]},{open:"[",close:"]",notIn:["string","comment"]},{open:"(",close:")",notIn:["string","comment"]},{open:"{",close:"}",notIn:["string","comment"]}]},T=exports.language={defaultToken:"",tokenPostfix:".msdax",ignoreCase:!0,brackets:[{open:"[",close:"]",token:"delimiter.square"},{open:"{",close:"}",token:"delimiter.brackets"},{open:"(",close:")",token:"delimiter.parenthesis"}],keywords:["VAR","RETURN","NOT","EVALUATE","DATATABLE","ORDER","BY","START","AT","DEFINE","MEASURE","ASC","DESC","IN","BOOLEAN","DOUBLE","INTEGER","DATETIME","CURRENCY","STRING"],functions:["CLOSINGBALANCEMONTH","CLOSINGBALANCEQUARTER","CLOSINGBALANCEYEAR","DATEADD","DATESBETWEEN","DATESINPERIOD","DATESMTD","DATESQTD","DATESYTD","ENDOFMONTH","ENDOFQUARTER","ENDOFYEAR","FIRSTDATE","FIRSTNONBLANK","LASTDATE","LASTNONBLANK","NEXTDAY","NEXTMONTH","NEXTQUARTER","NEXTYEAR","OPENINGBALANCEMONTH","OPENINGBALANCEQUARTER","OPENINGBALANCEYEAR","PARALLELPERIOD","PREVIOUSDAY","PREVIOUSMONTH","PREVIOUSQUARTER","PREVIOUSYEAR","SAMEPERIODLASTYEAR","STARTOFMONTH","STARTOFQUARTER","STARTOFYEAR","TOTALMTD","TOTALQTD","TOTALYTD","ADDCOLUMNS","ADDMISSINGITEMS","ALL","ALLEXCEPT","ALLNOBLANKROW","ALLSELECTED","CALCULATE","CALCULATETABLE","CALENDAR","CALENDARAUTO","CROSSFILTER","CROSSJOIN","CURRENTGROUP","DATATABLE","DETAILROWS","DISTINCT","EARLIER","EARLIEST","EXCEPT","FILTER","FILTERS","GENERATE","GENERATEALL","GROUPBY","IGNORE","INTERSECT","ISONORAFTER","KEEPFILTERS","LOOKUPVALUE","NATURALINNERJOIN","NATURALLEFTOUTERJOIN","RELATED","RELATEDTABLE","ROLLUP","ROLLUPADDISSUBTOTAL","ROLLUPGROUP","ROLLUPISSUBTOTAL","ROW","SAMPLE","SELECTCOLUMNS","SUBSTITUTEWITHINDEX","SUMMARIZE","SUMMARIZECOLUMNS","TOPN","TREATAS","UNION","USERELATIONSHIP","VALUES","SUM","SUMX","PATH","PATHCONTAINS","PATHITEM","PATHITEMREVERSE","PATHLENGTH","AVERAGE","AVERAGEA","AVERAGEX","COUNT","COUNTA","COUNTAX","COUNTBLANK","COUNTROWS","COUNTX","DISTINCTCOUNT","DIVIDE","GEOMEAN","GEOMEANX","MAX","MAXA","MAXX","MEDIAN","MEDIANX","MIN","MINA","MINX","PERCENTILE.EXC","PERCENTILE.INC","PERCENTILEX.EXC","PERCENTILEX.INC","PRODUCT","PRODUCTX","RANK.EQ","RANKX","STDEV.P","STDEV.S","STDEVX.P","STDEVX.S","VAR.P","VAR.S","VARX.P","VARX.S","XIRR","XNPV","DATE","DATEDIFF","DATEVALUE","DAY","EDATE","EOMONTH","HOUR","MINUTE","MONTH","NOW","SECOND","TIME","TIMEVALUE","TODAY","WEEKDAY","WEEKNUM","YEAR","YEARFRAC","CONTAINS","CONTAINSROW","CUSTOMDATA","ERROR","HASONEFILTER","HASONEVALUE","ISBLANK","ISCROSSFILTERED","ISEMPTY","ISERROR","ISEVEN","ISFILTERED","ISLOGICAL","ISNONTEXT","ISNUMBER","ISODD","ISSUBTOTAL","ISTEXT","USERNAME","USERPRINCIPALNAME","AND","FALSE","IF","IFERROR","NOT","OR","SWITCH","TRUE","ABS","ACOS","ACOSH","ACOT","ACOTH","ASIN","ASINH","ATAN","ATANH","BETA.DIST","BETA.INV","CEILING","CHISQ.DIST","CHISQ.DIST.RT","CHISQ.INV","CHISQ.INV.RT","COMBIN","COMBINA","CONFIDENCE.NORM","CONFIDENCE.T","COS","COSH","COT","COTH","CURRENCY","DEGREES","EVEN","EXP","EXPON.DIST","FACT","FLOOR","GCD","INT","ISO.CEILING","LCM","LN","LOG","LOG10","MOD","MROUND","ODD","PERMUT","PI","POISSON.DIST","POWER","QUOTIENT","RADIANS","RAND","RANDBETWEEN","ROUND","ROUNDDOWN","ROUNDUP","SIGN","SIN","SINH","SQRT","SQRTPI","TAN","TANH","TRUNC","BLANK","CONCATENATE","CONCATENATEX","EXACT","FIND","FIXED","FORMAT","LEFT","LEN","LOWER","MID","REPLACE","REPT","RIGHT","SEARCH","SUBSTITUTE","TRIM","UNICHAR","UNICODE","UPPER","VALUE"],tokenizer:{root:[{include:"@comments"},{include:"@whitespace"},{include:"@numbers"},{include:"@strings"},{include:"@complexIdentifiers"},[/[;,.]/,"delimiter"],[/[({})]/,"@brackets"],[/[a-z_][a-zA-Z0-9_]*/,{cases:{"@keywords":"keyword","@functions":"keyword","@default":"identifier"}}],[/[<>=!%&+\-*/|~^]/,"operator"]],whitespace:[[/\s+/,"white"]],comments:[[/\/\/+.*/,"comment"],[/\/\*/,{token:"comment.quote",next:"@comment"}]],comment:[[/[^*/]+/,"comment"],[/\*\//,{token:"comment.quote",next:"@pop"}],[/./,"comment"]],numbers:[[/0[xX][0-9a-fA-F]*/,"number"],[/[$][+-]*\d*(\.\d*)?/,"number"],[/((\d+(\.\d*)?)|(\.\d+))([eE][\-+]?\d+)?/,"number"]],strings:[[/N"/,{token:"string",next:"@string"}],[/"/,{token:"string",next:"@string"}]],string:[[/[^"]+/,"string"],[/""/,"string"],[/"/,{token:"string",next:"@pop"}]],complexIdentifiers:[[/\[/,{token:"identifier.quote",next:"@bracketedIdentifier"}],[/'/,{token:"identifier.quote",next:"@quotedIdentifier"}]],bracketedIdentifier:[[/[^\]]+/,"identifier"],[/]]/,"identifier"],[/]/,{token:"identifier.quote",next:"@pop"}]],quotedIdentifier:[[/[^']+/,"identifier"],[/''/,"identifier"],[/'/,{token:"identifier.quote",next:"@pop"}]]}};
},{}]},{},[682], null)
//# sourceMappingURL=msdax.33486e8e.map