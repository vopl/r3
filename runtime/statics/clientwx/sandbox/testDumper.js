function test(a,b)
{
	let data=
	{
		undef: undefined,
		null: null,
		bool: true,
		int: 220,
		float: 380.45,
		string: "str\r\n\t",
		obj:{a:'a'},
		arr:[1,2,3],
		func:test,
		xml:<a prop="val">text</a>,
		date: new Date(),
		args: arguments,
		
		get propWithGetter(){return this.obj},
		set propWithSetter(v){return this.obj=v},
		
		err:(function(){try{bug}catch(e){return e}})(),
		math:Math,
		
		rex1: new RegExp("",'g'),
		rex2: /dsfg/g,
		
		deep:[{a:[{b:23,c:[],d:{},e:[1,2],f:{1:1,2:2},j:[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]}]}],
	};

	data.recursive1 = data;
	data.recursive2 = data.arr;
	

	let dumper = include('dumper.js');
	
	//dumper.dump(data);
	print(dumper.dumps(data, 10, '  ')); //same as previous
}

test(1,'two');
