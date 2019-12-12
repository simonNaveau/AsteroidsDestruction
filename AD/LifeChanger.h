#ifndef LIFECHANGER_H
#define LIFECHANGER_H

/*!
 * \brief The LifeChanger class represent a value to change on the spaceship LP on contact
 */
class LifeChanger {

public:
    /*!
     * \brief LifeChanger Constructor of the class
     * \param lifeChange The value to change on the spaceship LP
     */
    LifeChanger(int lifeChange);

    /*!
     * \brief lifeChange Value of the change
     */
    int lifeChange;
};

#endif // LIFECHANGER_H
