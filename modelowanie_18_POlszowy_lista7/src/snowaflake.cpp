//
//  snowaflake.cpp
//  modelowanie_18_POlszowy_lista7
//
//  Created by Jan Śnieg on 03/06/2018.
//

#include "snowaflake.hpp"

void Koch(std::list<Line*> &lines)
{
    std::list<Line*> newLines; //For getting new Line*(s)
    std::list<Line*> delLines; //For getting Line*(s) to be deleted
    for(auto&& itr : lines)
    {
        ofVec2f l1 = ofVec2f((*itr).position);
        double len_l1 = (*itr).length/3;
        double ang_l1 = (*itr).angle;
        
        ofVec2f l2 = ofVec2f((*itr).position.x + (cos((*itr).angle*(M_PI/180.0))*(*itr).length/1.5), (*itr).position.y + (sin((*itr).angle*(M_PI/180.0))*(*itr).length/1.5));
        double len_l2 = (*itr).length/3;
        double ang_l2 = (*itr).angle;
        
        ofVec2f l3 = ofVec2f((*itr).position.x + (cos((*itr).angle*(M_PI/180.0))*(*itr).length/3.0), (*itr).position.y + (sin((*itr).angle*(M_PI/180.0))*(*itr).length/3.0));
        double len_l3 = (*itr).length/3.0;
        double ang_l3 = (*itr).angle - 300.0;
        
        ofVec2f l4 = ofVec2f((*itr).position.x + (cos((*itr).angle*(M_PI/180.0))*((*itr).length/1.5)), (*itr).position.y + (sin((*itr).angle*(M_PI/180.0))*((*itr).length/1.5)));
        double len_l4 = (*itr).length/3.0;
        double ang_l4 = (*itr).angle - 240.0;
        
        //All four lines properties are setted above!
        
        //Fixing bug - Changing Triangle Forming Orientation
        l4 = ofVec2f(l4.x + cos(ang_l4*(M_PI/180.0))*len_l4, l4.y + sin(ang_l4*(M_PI/180.0))*len_l4);
        ang_l4 -= 180.0;
        
        //Each line forms four new lines...
        newLines.push_back( new Line( l1, len_l1, ang_l1 ) );
        newLines.push_back( new Line( l2, len_l2, ang_l2 ) );
        newLines.push_back( new Line( l3, len_l3, ang_l3 ) );
        newLines.push_back( new Line( l4, len_l4, ang_l4 ) );
        
        //...for deleting itself!
        delLines.push_back( itr );
    }
    for(auto&& itr : newLines)
        lines.push_back( itr ); //Adding new Line*(s)
    
    for(auto itr : delLines)
    {
        lines.remove( itr ); //Deleting new Line*(s)
        delete itr;
    }
}
