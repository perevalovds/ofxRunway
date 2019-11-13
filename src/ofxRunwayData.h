//
//  ofxRunwayData.hpp
//  ofxRunway_BM-densecap
//
//  Created by Roy Macdonald on 11/11/19.
//
//
#pragma once
#include "ofMain.h"

enum ofxRunwayImageType{
	OFX_RUNWAY_JPG,
	OFX_RUNWAY_PNG
};

class ofxRunwayData {
public:
	string address;

	void setImage(const string& name,
				  const ofBaseHasPixels& pixels,
				  ofxRunwayImageType type, int width = 0, int height = 0);

	void setImage(const string& name,
				  const ofPixels& pixels,
				  ofxRunwayImageType type,
				  int width = 0, int height = 0);
	
	void setBoolean(const string& name, bool b);
	void setInt(const string& name, int i);
	void setFloat(const string& name, float f);
	void setString(const string& name, const string& s);
	void setFloats(const string& name, const vector<float>& f);
	void setStrings(const string& name, const vector<string>& s);
	void setFloatVectors(const string& name,const vector<vector<float> >& v);
	
	

	bool getImage(const string& name,ofBaseHasPixels& pixels);
	bool getImage(const string& name, ofPixels& pixels);
	bool getBoolean(const string& name, bool &b);
	bool getInt(const string& name, int& i);
	bool getFloat(const string& name, float& f);
	bool getString(const string& name, string& s);
	bool getFloats(const string& name, vector<float>& f);
	bool getStrings(const string& name, vector<string>& s);
	bool getFloatVectors(const string& name, vector<vector<float> >& v);
	
	
	ofJson data;
	
protected:
	bool checkSetData(const string& name, const string& callerName);
	template<typename T>
	bool getData(const string& name, const vector<string>& type_names, T& i, bool bIsVector = false);
	template<typename T>
	bool getDataArray(const string& name, const vector<string>& type_names, vector<T>& v);
};
